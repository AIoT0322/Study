
namespace stock
{
    partial class Form2
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea2 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend2 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series2 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this.Tap_Back = new System.Windows.Forms.Panel();
            this.Tab_Menu_Back = new System.Windows.Forms.Panel();
            this.closebutton = new System.Windows.Forms.Button();
            this.Tab_Menu_Select_Bar = new System.Windows.Forms.Panel();
            this.Tab_Menu_Select_Back = new System.Windows.Forms.Panel();
            this.btn_Menu1 = new System.Windows.Forms.Label();
            this.btn_Menu2 = new System.Windows.Forms.Label();
            this.btn_Menu3 = new System.Windows.Forms.Label();
            this.btn_Menu4 = new System.Windows.Forms.Label();
            this.Tab_Main = new System.Windows.Forms.TabControl();
            this.Tab_1 = new System.Windows.Forms.TabPage();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.price_textbox = new System.Windows.Forms.TextBox();
            this.cost_textbox = new System.Windows.Forms.TextBox();
            this.name_textbox = new System.Windows.Forms.TextBox();
            this.category_textbox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.code_textbox = new System.Windows.Forms.TextBox();
            this.register_button = new System.Windows.Forms.Button();
            this.Tab_2 = new System.Windows.Forms.TabPage();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.order_button = new System.Windows.Forms.Button();
            this.tableLayoutPanel2 = new System.Windows.Forms.TableLayoutPanel();
            this.cnt_order_textbox = new System.Windows.Forms.TextBox();
            this.cost_order_textbox = new System.Windows.Forms.TextBox();
            this.exp_order_textbox = new System.Windows.Forms.TextBox();
            this.name_order_textbox = new System.Windows.Forms.TextBox();
            this.label11 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.code_order_textbox = new System.Windows.Forms.TextBox();
            this.Tab_3 = new System.Windows.Forms.TabPage();
            this.dataGridView2 = new System.Windows.Forms.DataGridView();
            this.next_date = new System.Windows.Forms.PictureBox();
            this.date_label = new System.Windows.Forms.Label();
            this.Tab_4 = new System.Windows.Forms.TabPage();
            this.chart1 = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.Tap_Back.SuspendLayout();
            this.Tab_Menu_Back.SuspendLayout();
            this.Tab_Main.SuspendLayout();
            this.Tab_1.SuspendLayout();
            this.tableLayoutPanel1.SuspendLayout();
            this.Tab_2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.tableLayoutPanel2.SuspendLayout();
            this.Tab_3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.next_date)).BeginInit();
            this.Tab_4.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).BeginInit();
            this.SuspendLayout();
            // 
            // Tap_Back
            // 
            this.Tap_Back.BackColor = System.Drawing.Color.White;
            this.Tap_Back.Controls.Add(this.Tab_Menu_Back);
            this.Tap_Back.Controls.Add(this.Tab_Main);
            this.Tap_Back.Dock = System.Windows.Forms.DockStyle.Fill;
            this.Tap_Back.Location = new System.Drawing.Point(0, 0);
            this.Tap_Back.Name = "Tap_Back";
            this.Tap_Back.Size = new System.Drawing.Size(700, 500);
            this.Tap_Back.TabIndex = 0;
            // 
            // Tab_Menu_Back
            // 
            this.Tab_Menu_Back.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.Tab_Menu_Back.BackColor = System.Drawing.Color.White;
            this.Tab_Menu_Back.Controls.Add(this.closebutton);
            this.Tab_Menu_Back.Controls.Add(this.Tab_Menu_Select_Bar);
            this.Tab_Menu_Back.Controls.Add(this.Tab_Menu_Select_Back);
            this.Tab_Menu_Back.Controls.Add(this.btn_Menu1);
            this.Tab_Menu_Back.Controls.Add(this.btn_Menu2);
            this.Tab_Menu_Back.Controls.Add(this.btn_Menu3);
            this.Tab_Menu_Back.Controls.Add(this.btn_Menu4);
            this.Tab_Menu_Back.Location = new System.Drawing.Point(0, 1);
            this.Tab_Menu_Back.Name = "Tab_Menu_Back";
            this.Tab_Menu_Back.Size = new System.Drawing.Size(700, 50);
            this.Tab_Menu_Back.TabIndex = 0;
            this.Tab_Menu_Back.MouseDown += new System.Windows.Forms.MouseEventHandler(this.Tab_Menu_Back_MouseDown);
            this.Tab_Menu_Back.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Tab_Menu_Back_MouseMove);
            // 
            // closebutton
            // 
            this.closebutton.FlatAppearance.BorderSize = 0;
            this.closebutton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.closebutton.Image = global::stock.Properties.Resources.x;
            this.closebutton.Location = new System.Drawing.Point(680, -1);
            this.closebutton.Name = "closebutton";
            this.closebutton.Size = new System.Drawing.Size(23, 18);
            this.closebutton.TabIndex = 7;
            this.closebutton.UseVisualStyleBackColor = true;
            this.closebutton.Click += new System.EventHandler(this.closebutton_Click);
            // 
            // Tab_Menu_Select_Bar
            // 
            this.Tab_Menu_Select_Bar.BackColor = System.Drawing.SystemColors.HotTrack;
            this.Tab_Menu_Select_Bar.Location = new System.Drawing.Point(0, 46);
            this.Tab_Menu_Select_Bar.Name = "Tab_Menu_Select_Bar";
            this.Tab_Menu_Select_Bar.Size = new System.Drawing.Size(150, 3);
            this.Tab_Menu_Select_Bar.TabIndex = 0;
            // 
            // Tab_Menu_Select_Back
            // 
            this.Tab_Menu_Select_Back.BackColor = System.Drawing.Color.DarkGray;
            this.Tab_Menu_Select_Back.ForeColor = System.Drawing.SystemColors.ControlText;
            this.Tab_Menu_Select_Back.Location = new System.Drawing.Point(0, 46);
            this.Tab_Menu_Select_Back.Name = "Tab_Menu_Select_Back";
            this.Tab_Menu_Select_Back.Size = new System.Drawing.Size(700, 3);
            this.Tab_Menu_Select_Back.TabIndex = 0;
            // 
            // btn_Menu1
            // 
            this.btn_Menu1.Font = new System.Drawing.Font("맑은 고딕", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.btn_Menu1.ForeColor = System.Drawing.SystemColors.HotTrack;
            this.btn_Menu1.Location = new System.Drawing.Point(0, -1);
            this.btn_Menu1.Name = "btn_Menu1";
            this.btn_Menu1.Size = new System.Drawing.Size(150, 50);
            this.btn_Menu1.TabIndex = 1;
            this.btn_Menu1.Text = "상품등록";
            this.btn_Menu1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.btn_Menu1.Click += new System.EventHandler(this.btn_Menu1_Click);
            // 
            // btn_Menu2
            // 
            this.btn_Menu2.Font = new System.Drawing.Font("맑은 고딕", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.btn_Menu2.ForeColor = System.Drawing.Color.DarkGray;
            this.btn_Menu2.Location = new System.Drawing.Point(148, -1);
            this.btn_Menu2.Name = "btn_Menu2";
            this.btn_Menu2.Size = new System.Drawing.Size(155, 50);
            this.btn_Menu2.TabIndex = 2;
            this.btn_Menu2.Text = "상품주문";
            this.btn_Menu2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.btn_Menu2.Click += new System.EventHandler(this.btn_Menu2_Click);
            // 
            // btn_Menu3
            // 
            this.btn_Menu3.Font = new System.Drawing.Font("맑은 고딕", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.btn_Menu3.ForeColor = System.Drawing.Color.DarkGray;
            this.btn_Menu3.Location = new System.Drawing.Point(300, -1);
            this.btn_Menu3.Name = "btn_Menu3";
            this.btn_Menu3.Size = new System.Drawing.Size(157, 50);
            this.btn_Menu3.TabIndex = 3;
            this.btn_Menu3.Text = "재고확인";
            this.btn_Menu3.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.btn_Menu3.Click += new System.EventHandler(this.btn_Menu3_Click);
            // 
            // btn_Menu4
            // 
            this.btn_Menu4.Font = new System.Drawing.Font("맑은 고딕", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.btn_Menu4.ForeColor = System.Drawing.Color.DarkGray;
            this.btn_Menu4.Location = new System.Drawing.Point(450, -1);
            this.btn_Menu4.Name = "btn_Menu4";
            this.btn_Menu4.Size = new System.Drawing.Size(157, 50);
            this.btn_Menu4.TabIndex = 8;
            this.btn_Menu4.Text = "통계";
            this.btn_Menu4.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.btn_Menu4.Click += new System.EventHandler(this.btn_Menu4_Click);
            // 
            // Tab_Main
            // 
            this.Tab_Main.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.Tab_Main.Controls.Add(this.Tab_1);
            this.Tab_Main.Controls.Add(this.Tab_2);
            this.Tab_Main.Controls.Add(this.Tab_3);
            this.Tab_Main.Controls.Add(this.Tab_4);
            this.Tab_Main.Location = new System.Drawing.Point(0, 28);
            this.Tab_Main.Name = "Tab_Main";
            this.Tab_Main.SelectedIndex = 0;
            this.Tab_Main.Size = new System.Drawing.Size(700, 473);
            this.Tab_Main.TabIndex = 1;
            // 
            // Tab_1
            // 
            this.Tab_1.Controls.Add(this.tableLayoutPanel1);
            this.Tab_1.Controls.Add(this.register_button);
            this.Tab_1.Location = new System.Drawing.Point(4, 22);
            this.Tab_1.Name = "Tab_1";
            this.Tab_1.Padding = new System.Windows.Forms.Padding(3);
            this.Tab_1.Size = new System.Drawing.Size(692, 447);
            this.Tab_1.TabIndex = 0;
            this.Tab_1.Text = "tabPage1";
            this.Tab_1.UseVisualStyleBackColor = true;
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.AutoSize = true;
            this.tableLayoutPanel1.ColumnCount = 2;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 23.21725F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 76.78275F));
            this.tableLayoutPanel1.Controls.Add(this.price_textbox, 1, 4);
            this.tableLayoutPanel1.Controls.Add(this.cost_textbox, 1, 3);
            this.tableLayoutPanel1.Controls.Add(this.name_textbox, 1, 2);
            this.tableLayoutPanel1.Controls.Add(this.category_textbox, 1, 1);
            this.tableLayoutPanel1.Controls.Add(this.label1, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.label2, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.label3, 0, 2);
            this.tableLayoutPanel1.Controls.Add(this.label4, 0, 3);
            this.tableLayoutPanel1.Controls.Add(this.label5, 0, 4);
            this.tableLayoutPanel1.Controls.Add(this.code_textbox, 1, 0);
            this.tableLayoutPanel1.Location = new System.Drawing.Point(79, 39);
            this.tableLayoutPanel1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 5;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 16.66667F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 16.66667F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 16.66667F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 16.66667F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 16.66667F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(535, 320);
            this.tableLayoutPanel1.TabIndex = 11;
            // 
            // price_textbox
            // 
            this.price_textbox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.price_textbox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.price_textbox.Font = new System.Drawing.Font("맑은 고딕", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.price_textbox.Location = new System.Drawing.Point(127, 254);
            this.price_textbox.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.price_textbox.Multiline = true;
            this.price_textbox.Name = "price_textbox";
            this.price_textbox.Size = new System.Drawing.Size(405, 64);
            this.price_textbox.TabIndex = 10;
            // 
            // cost_textbox
            // 
            this.cost_textbox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.cost_textbox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cost_textbox.Font = new System.Drawing.Font("맑은 고딕", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.cost_textbox.Location = new System.Drawing.Point(127, 191);
            this.cost_textbox.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.cost_textbox.Multiline = true;
            this.cost_textbox.Name = "cost_textbox";
            this.cost_textbox.Size = new System.Drawing.Size(405, 59);
            this.cost_textbox.TabIndex = 9;
            // 
            // name_textbox
            // 
            this.name_textbox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.name_textbox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.name_textbox.Font = new System.Drawing.Font("맑은 고딕", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.name_textbox.Location = new System.Drawing.Point(127, 128);
            this.name_textbox.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.name_textbox.Multiline = true;
            this.name_textbox.Name = "name_textbox";
            this.name_textbox.Size = new System.Drawing.Size(405, 59);
            this.name_textbox.TabIndex = 8;
            // 
            // category_textbox
            // 
            this.category_textbox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.category_textbox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.category_textbox.Font = new System.Drawing.Font("맑은 고딕", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.category_textbox.Location = new System.Drawing.Point(127, 65);
            this.category_textbox.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.category_textbox.Multiline = true;
            this.category_textbox.Name = "category_textbox";
            this.category_textbox.Size = new System.Drawing.Size(405, 59);
            this.category_textbox.TabIndex = 7;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.SystemColors.HotTrack;
            this.label1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.label1.Font = new System.Drawing.Font("맑은 고딕", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label1.ForeColor = System.Drawing.Color.White;
            this.label1.Location = new System.Drawing.Point(3, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(118, 63);
            this.label1.TabIndex = 0;
            this.label1.Text = "상품코드";
            this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.SystemColors.HotTrack;
            this.label2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.label2.Font = new System.Drawing.Font("맑은 고딕", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label2.ForeColor = System.Drawing.Color.White;
            this.label2.Location = new System.Drawing.Point(3, 63);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(118, 63);
            this.label2.TabIndex = 1;
            this.label2.Text = "분류";
            this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.SystemColors.HotTrack;
            this.label3.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.label3.Font = new System.Drawing.Font("맑은 고딕", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label3.ForeColor = System.Drawing.Color.White;
            this.label3.Location = new System.Drawing.Point(3, 126);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(118, 63);
            this.label3.TabIndex = 2;
            this.label3.Text = "상품명";
            this.label3.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.BackColor = System.Drawing.SystemColors.HotTrack;
            this.label4.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label4.Dock = System.Windows.Forms.DockStyle.Fill;
            this.label4.Font = new System.Drawing.Font("맑은 고딕", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label4.ForeColor = System.Drawing.Color.White;
            this.label4.Location = new System.Drawing.Point(3, 189);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(118, 63);
            this.label4.TabIndex = 3;
            this.label4.Text = "구매가";
            this.label4.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.BackColor = System.Drawing.SystemColors.HotTrack;
            this.label5.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label5.Dock = System.Windows.Forms.DockStyle.Fill;
            this.label5.Font = new System.Drawing.Font("맑은 고딕", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label5.ForeColor = System.Drawing.Color.White;
            this.label5.Location = new System.Drawing.Point(3, 252);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(118, 68);
            this.label5.TabIndex = 4;
            this.label5.Text = "판매가";
            this.label5.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // code_textbox
            // 
            this.code_textbox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.code_textbox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.code_textbox.Font = new System.Drawing.Font("맑은 고딕", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.code_textbox.Location = new System.Drawing.Point(127, 2);
            this.code_textbox.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.code_textbox.Multiline = true;
            this.code_textbox.Name = "code_textbox";
            this.code_textbox.Size = new System.Drawing.Size(405, 59);
            this.code_textbox.TabIndex = 6;
            // 
            // register_button
            // 
            this.register_button.BackColor = System.Drawing.Color.White;
            this.register_button.FlatAppearance.BorderColor = System.Drawing.Color.LightGray;
            this.register_button.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.register_button.Font = new System.Drawing.Font("맑은 고딕", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.register_button.ForeColor = System.Drawing.SystemColors.ControlText;
            this.register_button.Location = new System.Drawing.Point(300, 391);
            this.register_button.Name = "register_button";
            this.register_button.Size = new System.Drawing.Size(82, 30);
            this.register_button.TabIndex = 12;
            this.register_button.Text = "등록하기";
            this.register_button.UseVisualStyleBackColor = false;
            this.register_button.Click += new System.EventHandler(this.register_button_Click_1);
            // 
            // Tab_2
            // 
            this.Tab_2.Controls.Add(this.dataGridView1);
            this.Tab_2.Controls.Add(this.order_button);
            this.Tab_2.Controls.Add(this.tableLayoutPanel2);
            this.Tab_2.Location = new System.Drawing.Point(4, 22);
            this.Tab_2.Name = "Tab_2";
            this.Tab_2.Padding = new System.Windows.Forms.Padding(3);
            this.Tab_2.Size = new System.Drawing.Size(692, 447);
            this.Tab_2.TabIndex = 1;
            this.Tab_2.Text = "tabPage2";
            this.Tab_2.UseVisualStyleBackColor = true;
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(74, 41);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowTemplate.Height = 23;
            this.dataGridView1.Size = new System.Drawing.Size(543, 172);
            this.dataGridView1.TabIndex = 14;
            // 
            // order_button
            // 
            this.order_button.BackColor = System.Drawing.Color.White;
            this.order_button.FlatAppearance.BorderColor = System.Drawing.Color.LightGray;
            this.order_button.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.order_button.Font = new System.Drawing.Font("맑은 고딕", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.order_button.ForeColor = System.Drawing.SystemColors.ControlText;
            this.order_button.Location = new System.Drawing.Point(304, 356);
            this.order_button.Name = "order_button";
            this.order_button.Size = new System.Drawing.Size(82, 30);
            this.order_button.TabIndex = 13;
            this.order_button.Text = "주문하기";
            this.order_button.UseVisualStyleBackColor = false;
            this.order_button.Click += new System.EventHandler(this.order_button_Click);
            // 
            // tableLayoutPanel2
            // 
            this.tableLayoutPanel2.ColumnCount = 5;
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tableLayoutPanel2.Controls.Add(this.cnt_order_textbox, 4, 1);
            this.tableLayoutPanel2.Controls.Add(this.cost_order_textbox, 3, 1);
            this.tableLayoutPanel2.Controls.Add(this.exp_order_textbox, 2, 1);
            this.tableLayoutPanel2.Controls.Add(this.name_order_textbox, 1, 1);
            this.tableLayoutPanel2.Controls.Add(this.label11, 4, 0);
            this.tableLayoutPanel2.Controls.Add(this.label10, 3, 0);
            this.tableLayoutPanel2.Controls.Add(this.label9, 2, 0);
            this.tableLayoutPanel2.Controls.Add(this.label8, 1, 0);
            this.tableLayoutPanel2.Controls.Add(this.label7, 0, 0);
            this.tableLayoutPanel2.Controls.Add(this.code_order_textbox, 0, 1);
            this.tableLayoutPanel2.Location = new System.Drawing.Point(74, 243);
            this.tableLayoutPanel2.Name = "tableLayoutPanel2";
            this.tableLayoutPanel2.RowCount = 2;
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tableLayoutPanel2.Size = new System.Drawing.Size(543, 89);
            this.tableLayoutPanel2.TabIndex = 0;
            // 
            // cnt_order_textbox
            // 
            this.cnt_order_textbox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cnt_order_textbox.Font = new System.Drawing.Font("맑은 고딕", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.cnt_order_textbox.Location = new System.Drawing.Point(435, 47);
            this.cnt_order_textbox.Multiline = true;
            this.cnt_order_textbox.Name = "cnt_order_textbox";
            this.cnt_order_textbox.Size = new System.Drawing.Size(105, 39);
            this.cnt_order_textbox.TabIndex = 9;
            this.cnt_order_textbox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // cost_order_textbox
            // 
            this.cost_order_textbox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cost_order_textbox.Font = new System.Drawing.Font("맑은 고딕", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.cost_order_textbox.Location = new System.Drawing.Point(327, 47);
            this.cost_order_textbox.Multiline = true;
            this.cost_order_textbox.Name = "cost_order_textbox";
            this.cost_order_textbox.Size = new System.Drawing.Size(102, 39);
            this.cost_order_textbox.TabIndex = 8;
            this.cost_order_textbox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // exp_order_textbox
            // 
            this.exp_order_textbox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.exp_order_textbox.Font = new System.Drawing.Font("맑은 고딕", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.exp_order_textbox.Location = new System.Drawing.Point(219, 47);
            this.exp_order_textbox.Multiline = true;
            this.exp_order_textbox.Name = "exp_order_textbox";
            this.exp_order_textbox.Size = new System.Drawing.Size(102, 39);
            this.exp_order_textbox.TabIndex = 7;
            this.exp_order_textbox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // name_order_textbox
            // 
            this.name_order_textbox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.name_order_textbox.Font = new System.Drawing.Font("맑은 고딕", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.name_order_textbox.Location = new System.Drawing.Point(111, 47);
            this.name_order_textbox.Multiline = true;
            this.name_order_textbox.Name = "name_order_textbox";
            this.name_order_textbox.Size = new System.Drawing.Size(102, 39);
            this.name_order_textbox.TabIndex = 6;
            this.name_order_textbox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.BackColor = System.Drawing.Color.DarkOrange;
            this.label11.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label11.Dock = System.Windows.Forms.DockStyle.Fill;
            this.label11.Font = new System.Drawing.Font("맑은 고딕", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label11.ForeColor = System.Drawing.Color.White;
            this.label11.Location = new System.Drawing.Point(435, 0);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(105, 44);
            this.label11.TabIndex = 5;
            this.label11.Text = "수량";
            this.label11.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.BackColor = System.Drawing.Color.DarkOrange;
            this.label10.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label10.Dock = System.Windows.Forms.DockStyle.Fill;
            this.label10.Font = new System.Drawing.Font("맑은 고딕", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label10.ForeColor = System.Drawing.Color.White;
            this.label10.Location = new System.Drawing.Point(327, 0);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(102, 44);
            this.label10.TabIndex = 4;
            this.label10.Text = "구매가";
            this.label10.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.BackColor = System.Drawing.Color.DarkOrange;
            this.label9.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label9.Dock = System.Windows.Forms.DockStyle.Fill;
            this.label9.Font = new System.Drawing.Font("맑은 고딕", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label9.ForeColor = System.Drawing.Color.White;
            this.label9.Location = new System.Drawing.Point(219, 0);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(102, 44);
            this.label9.TabIndex = 3;
            this.label9.Text = "유통기한";
            this.label9.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.BackColor = System.Drawing.Color.DarkOrange;
            this.label8.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label8.Dock = System.Windows.Forms.DockStyle.Fill;
            this.label8.Font = new System.Drawing.Font("맑은 고딕", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label8.ForeColor = System.Drawing.Color.White;
            this.label8.Location = new System.Drawing.Point(111, 0);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(102, 44);
            this.label8.TabIndex = 2;
            this.label8.Text = "상품명";
            this.label8.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.BackColor = System.Drawing.Color.DarkOrange;
            this.label7.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label7.Dock = System.Windows.Forms.DockStyle.Fill;
            this.label7.Font = new System.Drawing.Font("맑은 고딕", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label7.ForeColor = System.Drawing.Color.White;
            this.label7.Location = new System.Drawing.Point(3, 0);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(102, 44);
            this.label7.TabIndex = 0;
            this.label7.Text = "상품코드";
            this.label7.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // code_order_textbox
            // 
            this.code_order_textbox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.code_order_textbox.Font = new System.Drawing.Font("맑은 고딕", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.code_order_textbox.Location = new System.Drawing.Point(3, 47);
            this.code_order_textbox.Multiline = true;
            this.code_order_textbox.Name = "code_order_textbox";
            this.code_order_textbox.Size = new System.Drawing.Size(102, 39);
            this.code_order_textbox.TabIndex = 1;
            this.code_order_textbox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // Tab_3
            // 
            this.Tab_3.Controls.Add(this.dataGridView2);
            this.Tab_3.Controls.Add(this.next_date);
            this.Tab_3.Controls.Add(this.date_label);
            this.Tab_3.Location = new System.Drawing.Point(4, 22);
            this.Tab_3.Name = "Tab_3";
            this.Tab_3.Padding = new System.Windows.Forms.Padding(3);
            this.Tab_3.Size = new System.Drawing.Size(692, 447);
            this.Tab_3.TabIndex = 2;
            this.Tab_3.Text = "tabPage3";
            this.Tab_3.UseVisualStyleBackColor = true;
            // 
            // dataGridView2
            // 
            this.dataGridView2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView2.Location = new System.Drawing.Point(74, 94);
            this.dataGridView2.Name = "dataGridView2";
            this.dataGridView2.RowTemplate.Height = 23;
            this.dataGridView2.Size = new System.Drawing.Size(543, 219);
            this.dataGridView2.TabIndex = 2;
            // 
            // next_date
            // 
            this.next_date.Image = global::stock.Properties.Resources.화살표;
            this.next_date.Location = new System.Drawing.Point(661, 16);
            this.next_date.Name = "next_date";
            this.next_date.Size = new System.Drawing.Size(13, 21);
            this.next_date.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.next_date.TabIndex = 1;
            this.next_date.TabStop = false;
            this.next_date.Click += new System.EventHandler(this.next_date_Click);
            // 
            // date_label
            // 
            this.date_label.AutoSize = true;
            this.date_label.Font = new System.Drawing.Font("맑은 고딕", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.date_label.Location = new System.Drawing.Point(565, 15);
            this.date_label.Name = "date_label";
            this.date_label.Size = new System.Drawing.Size(96, 21);
            this.date_label.TabIndex = 0;
            this.date_label.Text = "2023-09-13";
            // 
            // Tab_4
            // 
            this.Tab_4.Controls.Add(this.chart1);
            this.Tab_4.Location = new System.Drawing.Point(4, 22);
            this.Tab_4.Name = "Tab_4";
            this.Tab_4.Padding = new System.Windows.Forms.Padding(3);
            this.Tab_4.Size = new System.Drawing.Size(692, 447);
            this.Tab_4.TabIndex = 3;
            this.Tab_4.Text = "tabPage4";
            this.Tab_4.UseVisualStyleBackColor = true;
            // 
            // chart1
            // 
            chartArea2.Name = "ChartArea1";
            this.chart1.ChartAreas.Add(chartArea2);
            legend2.Name = "Legend1";
            this.chart1.Legends.Add(legend2);
            this.chart1.Location = new System.Drawing.Point(113, 63);
            this.chart1.Name = "chart1";
            series2.ChartArea = "ChartArea1";
            series2.Legend = "Legend1";
            series2.Name = "Series1";
            this.chart1.Series.Add(series2);
            this.chart1.Size = new System.Drawing.Size(522, 300);
            this.chart1.TabIndex = 0;
            this.chart1.Text = "chart1";
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(700, 500);
            this.Controls.Add(this.Tap_Back);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "Form2";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form2";
            this.Load += new System.EventHandler(this.Form2_Load);
            this.Tap_Back.ResumeLayout(false);
            this.Tab_Menu_Back.ResumeLayout(false);
            this.Tab_Main.ResumeLayout(false);
            this.Tab_1.ResumeLayout(false);
            this.Tab_1.PerformLayout();
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            this.Tab_2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.tableLayoutPanel2.ResumeLayout(false);
            this.tableLayoutPanel2.PerformLayout();
            this.Tab_3.ResumeLayout(false);
            this.Tab_3.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.next_date)).EndInit();
            this.Tab_4.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel Tap_Back;
        private System.Windows.Forms.Panel Tab_Menu_Back;
        private System.Windows.Forms.Label btn_Menu1;
        private System.Windows.Forms.Label btn_Menu2;
        private System.Windows.Forms.Label btn_Menu3;
        private System.Windows.Forms.Panel Tab_Menu_Select_Bar;
        private System.Windows.Forms.Panel Tab_Menu_Select_Back;
        private System.Windows.Forms.Button closebutton;
        private System.Windows.Forms.Label btn_Menu4;
        private System.Windows.Forms.TabControl Tab_Main;
        private System.Windows.Forms.TabPage Tab_1;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.TextBox price_textbox;
        private System.Windows.Forms.TextBox cost_textbox;
        private System.Windows.Forms.TextBox name_textbox;
        private System.Windows.Forms.TextBox category_textbox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox code_textbox;
        private System.Windows.Forms.Button register_button;
        private System.Windows.Forms.TabPage Tab_2;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Button order_button;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel2;
        private System.Windows.Forms.TextBox cnt_order_textbox;
        private System.Windows.Forms.TextBox cost_order_textbox;
        private System.Windows.Forms.TextBox exp_order_textbox;
        private System.Windows.Forms.TextBox name_order_textbox;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox code_order_textbox;
        private System.Windows.Forms.TabPage Tab_3;
        private System.Windows.Forms.DataGridView dataGridView2;
        private System.Windows.Forms.PictureBox next_date;
        private System.Windows.Forms.Label date_label;
        private System.Windows.Forms.TabPage Tab_4;
        private System.Windows.Forms.DataVisualization.Charting.Chart chart1;
    }
}