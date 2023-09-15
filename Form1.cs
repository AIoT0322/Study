using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Puzzle
{
    public partial class Form1 : Form
    {
        Bitmap imageBitmap = null;
        List<Bitmap> dividedImages = new List<Bitmap>();
        Point mouseDownLocation;
        PictureBox clickedPictureBox = null;
        List<PictureBox> pictureBoxes = new List<PictureBox>();
        PictureBox emptyCellPictureBox = null; // 비어있는 셀 찾는 변수

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)  //버튼 클릭하면 파일 오픈
        {
            using (var od = new OpenFileDialog())
            {
                if (od.ShowDialog() == DialogResult.OK)
                {
                    imageBitmap = new Bitmap(od.FileName);
                    pictureBox1.Image = imageBitmap;
                }
            }
        }

        private void button2_Click(object sender, EventArgs e) //버튼 클릭하면 사진 나누고 섞기
        {
            if (imageBitmap == null) //사진파일 먼저 안 열면 에러 메시지 출력
            {
                MessageBox.Show("이미지를 먼저 열어주세요!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            int cellWidth = imageBitmap.Width / 5;   //사진 크기 5*5로 나누기
            int cellHeight = imageBitmap.Height / 5;

            dividedImages.Clear();
            pictureBoxes.Clear();
            pictureBox1.Controls.Clear();

            emptyCellPictureBox = null; // 새 게임 시작할 때 픽쳐박스 재설정

            //PictureBox2에서 PictureBox 컨트롤 지움
            pictureBox2.Controls.Clear();

            // 로드된 이미지 5x5 그리드 섹션으로 나누기
            using (Graphics graphics = Graphics.FromImage(imageBitmap))
            {
                for (int row = 0; row < 5; row++)
                {
                    for (int col = 0; col < 5; col++)
                    {
                        //각 그리드 섹션에 대해 소스 및 대상 직사각형을 정의
                        Rectangle sourceRect = new Rectangle(col * cellWidth, row * cellHeight, cellWidth, cellHeight);
                        Rectangle destinationRect = new Rectangle(col * cellWidth, row * cellHeight, cellWidth, cellHeight);

                        // 각 그리드 셀에 대해 새 비트맵을 만들고 원본 이미지의 해당 섹션을 그리기
                        Bitmap dividedImage = new Bitmap(cellWidth, cellHeight);
                        using (Graphics g = Graphics.FromImage(dividedImage))
                        {
                            g.DrawImage(imageBitmap, 0, 0, sourceRect, GraphicsUnit.Pixel);
                        }

                        dividedImages.Add(dividedImage);

                        // 각 그리드 셀에 대해 픽쳐박스를 만들고 속성을 설정
                        PictureBox pictureBox = new PictureBox 
                        {
                            Image = dividedImage,
                            SizeMode = PictureBoxSizeMode.StretchImage,
                            Location = new Point(col * cellWidth, row * cellHeight),
                            Size = new Size(cellWidth, cellHeight),
                            Tag = row * 5 + col // 태그 속성을 사용하여 각 PictureBox의 인덱스 저장
                        };

                        // 마우스 드래그를 처리할 픽쳐박스의 이벤트 핸들러를 등록
                        pictureBox.MouseDown += pictureBox_MouseDown;
                        pictureBox.MouseMove += pictureBox_MouseMove;
                        pictureBox.MouseUp += pictureBox_MouseUp;
                        pictureBox.AllowDrop = true; // PictureBox에 드롭 기능을 활성화
                        pictureBox.DragEnter += pictureBox_DragEnter;
                        pictureBox.DragDrop += pictureBox_DragDrop;

                        // PictureBoxes에 pictureBox2 추가
                        pictureBoxes.Add(pictureBox);
                        pictureBox2.Controls.Add(pictureBox);
                    }
                }
            }

            ShufflePictureBoxes(); // 픽쳐박스 섞기
            emptyCellPictureBox = pictureBoxes[24]; //셔플 후 빈 셀을 마지막 픽쳐박스로 설정
        }

        private void pictureBox_MouseDown(object sender, MouseEventArgs e)
        {
            // 클릭한 픽쳐박스와 마우스 클릭 위치를 저장
            clickedPictureBox = sender as PictureBox;
            mouseDownLocation = e.Location;
        }

        private void pictureBox_MouseMove(object sender, MouseEventArgs e)
        {
            // 마우스 클릭해서 움직인 픽쳐박스 이동
            if (clickedPictureBox == null || e.Button != MouseButtons.Left)
                return;

            clickedPictureBox.Left = e.X + clickedPictureBox.Left - mouseDownLocation.X;
            clickedPictureBox.Top = e.Y + clickedPictureBox.Top - mouseDownLocation.Y;
        }

        private void pictureBox_MouseUp(object sender, MouseEventArgs e)
        {
            // 마우스 버튼이 클릭이 해제되면 클릭한 픽쳐박스를 재설정
            clickedPictureBox = null;
        }

        private void pictureBox_DragEnter(object sender, DragEventArgs e)
        {
            //드래그한 데이터가 PictureBox 컨트롤인지 확인
            if (e.Data.GetDataPresent(typeof(PictureBox)))
            {
                //  드롭 허용
                e.Effect = DragDropEffects.Move;
            }
            else
            {
                // 드롭허용X
                e.Effect = DragDropEffects.None;
            }
        }

        private void pictureBox_DragDrop(object sender, DragEventArgs e)
        {
            // 드래그한 데이터가 PictureBox 컨트롤인지 확인
            if (e.Data.GetDataPresent(typeof(PictureBox)))
            {
                //드래그된 픽쳐박스 컨트롤 가져오기
                PictureBox draggedPictureBox = (PictureBox)e.Data.GetData(typeof(PictureBox));

                //드래그한 PictureBox와 드롭한 PictureBox의 위치를 바꾸기
                Point tempLocation = draggedPictureBox.Location;
                draggedPictureBox.Location = ((PictureBox)sender).Location;
                ((PictureBox)sender).Location = tempLocation;

                //리스트에서 드래그한 픽쳐박스 및 드롭한 픽쳐박스의 인덱스를 업데이트
                int draggedIndex = (int)draggedPictureBox.Tag;
                int emptyIndex = (int)((PictureBox)sender).Tag;
                dividedImages[draggedIndex] = new Bitmap(emptyCellPictureBox.Image);
                dividedImages[emptyIndex] = new Bitmap(draggedPictureBox.Image);

                //드래그한 픽쳐박스와 드롭한 픽쳐박스 태그를 업데이트
                draggedPictureBox.Tag = emptyIndex;
                ((PictureBox)sender).Tag = draggedIndex;

                //빈 셀을 나타내는 픽쳐박스에 참조 업데이트
                emptyCellPictureBox = (PictureBox)sender;

                //각 이동 후 퍼즐이 풀렸는지 확인(드래그 앤 드롭 작업).
                CheckPuzzleSolved();
            }
        }

        private void SwapPictureBoxes(PictureBox pictureBox1, PictureBox pictureBox2)
        {
            // 두 픽쳐박스의 위치 바꾸기
            Point tempLocation = pictureBox1.Location;
            pictureBox1.Location = pictureBox2.Location;
            pictureBox2.Location = tempLocation;
        }

        private void ShufflePictureBoxes()
        {
            // 사진 섞기
            Random rng = new Random();
            int n = pictureBoxes.Count;
            while (n > 1)
            {
                n--;
                int k = rng.Next(n + 1);
                SwapPictureBoxes(pictureBoxes[k], pictureBoxes[n]);
            }
        }

        private bool IsPuzzleSolved()
        {
            // PictureBox 태그의 인덱스를 비교하여 퍼즐이 풀렸는지 확인
            for (int i = 0; i < pictureBoxes.Count; i++)
            {
                int cellIndex = (int)pictureBoxes[i].Tag;
                if (cellIndex != i)
                {
                    return false; // 만약 어떤 픽쳐박스 인덱스가 처음 위치랑 맞지 않으면 퍼즐 안 풀린 것
                }
            }
            return true; //모든 픽쳐박스가 처음 위치로되면 퍼즐 풀린 것
        }

        private void CheckPuzzleSolved()
        {
            // 각 이동 후 퍼즐이 풀렸는지 확인(드래그 앤 드롭 작업)
            if (IsPuzzleSolved())
            {
                MessageBox.Show("퍼즐 완성!", "Puzzle Solved", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }
    }
}
