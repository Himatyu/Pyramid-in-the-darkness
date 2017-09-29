namespace ScriptableObjectEditor
{
    partial class Main
    {
        /// <summary>
        /// 必要なデザイナー変数です。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 使用中のリソースをすべてクリーンアップします。
        /// </summary>
        /// <param name="disposing">マネージ リソースを破棄する場合は true を指定し、その他の場合は false を指定します。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows フォーム デザイナーで生成されたコード

        /// <summary>
        /// デザイナー サポートに必要なメソッドです。このメソッドの内容を
        /// コード エディターで変更しないでください。
        /// </summary>
        private void InitializeComponent()
        {
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.RegisterAccept = new System.Windows.Forms.Button();
            this.ClassStructVeiw = new System.Windows.Forms.ListView();
            this.SelectClassName = new System.Windows.Forms.Label();
            this.RegistClassSelectButton = new System.Windows.Forms.Button();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.CreateAccept = new System.Windows.Forms.Button();
            this.ValueData = new System.Windows.Forms.DataGridView();
            this.type = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.value = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.SelectedClass = new System.Windows.Forms.Label();
            this.ClassMenberSelect = new System.Windows.Forms.ListBox();
            this.RegistedClassSelect = new System.Windows.Forms.ListBox();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.ModifyAccept = new System.Windows.Forms.Button();
            this.ValueData_Modify = new System.Windows.Forms.DataGridView();
            this.ModifyType = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ModifyValue = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ClassMenberSelect_Modify = new System.Windows.Forms.ListBox();
            this.RegistedClassSelect_Modify = new System.Windows.Forms.ListBox();
            this.SelectModify = new System.Windows.Forms.Label();
            this.ModifySelect = new System.Windows.Forms.Button();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.ValueData)).BeginInit();
            this.tabPage3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.ValueData_Modify)).BeginInit();
            this.SuspendLayout();
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Controls.Add(this.tabPage3);
            this.tabControl1.Location = new System.Drawing.Point(13, 13);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(953, 644);
            this.tabControl1.TabIndex = 0;
            this.tabControl1.SelectedIndexChanged += new System.EventHandler(this.tabControl1_SelectedIndexChanged);
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.RegisterAccept);
            this.tabPage1.Controls.Add(this.ClassStructVeiw);
            this.tabPage1.Controls.Add(this.SelectClassName);
            this.tabPage1.Controls.Add(this.RegistClassSelectButton);
            this.tabPage1.Location = new System.Drawing.Point(4, 25);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(945, 615);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Register";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // RegisterAccept
            // 
            this.RegisterAccept.Location = new System.Drawing.Point(828, 567);
            this.RegisterAccept.Name = "RegisterAccept";
            this.RegisterAccept.Size = new System.Drawing.Size(100, 33);
            this.RegisterAccept.TabIndex = 5;
            this.RegisterAccept.Text = "登録";
            this.RegisterAccept.UseVisualStyleBackColor = true;
            this.RegisterAccept.Click += new System.EventHandler(this.RegisterAccept_Click);
            // 
            // ClassStructVeiw
            // 
            this.ClassStructVeiw.Location = new System.Drawing.Point(20, 82);
            this.ClassStructVeiw.Name = "ClassStructVeiw";
            this.ClassStructVeiw.Size = new System.Drawing.Size(908, 468);
            this.ClassStructVeiw.TabIndex = 3;
            this.ClassStructVeiw.UseCompatibleStateImageBehavior = false;
            this.ClassStructVeiw.SelectedIndexChanged += new System.EventHandler(this.ClassStructVeiw_SelectedIndexChanged);
            // 
            // SelectClassName
            // 
            this.SelectClassName.AutoSize = true;
            this.SelectClassName.Cursor = System.Windows.Forms.Cursors.SizeNWSE;
            this.SelectClassName.Location = new System.Drawing.Point(176, 37);
            this.SelectClassName.Name = "SelectClassName";
            this.SelectClassName.Size = new System.Drawing.Size(52, 15);
            this.SelectClassName.TabIndex = 1;
            this.SelectClassName.Text = "未選択";
            // 
            // RegistClassSelectButton
            // 
            this.RegistClassSelectButton.Location = new System.Drawing.Point(20, 26);
            this.RegistClassSelectButton.Name = "RegistClassSelectButton";
            this.RegistClassSelectButton.Size = new System.Drawing.Size(124, 37);
            this.RegistClassSelectButton.TabIndex = 0;
            this.RegistClassSelectButton.Text = "型選択";
            this.RegistClassSelectButton.UseVisualStyleBackColor = true;
            this.RegistClassSelectButton.Click += new System.EventHandler(this.RegistClassSelectButton_Click);
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.CreateAccept);
            this.tabPage2.Controls.Add(this.ValueData);
            this.tabPage2.Controls.Add(this.SelectedClass);
            this.tabPage2.Controls.Add(this.ClassMenberSelect);
            this.tabPage2.Controls.Add(this.RegistedClassSelect);
            this.tabPage2.Location = new System.Drawing.Point(4, 25);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(945, 615);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Creater";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // CreateAccept
            // 
            this.CreateAccept.Location = new System.Drawing.Point(797, 558);
            this.CreateAccept.Name = "CreateAccept";
            this.CreateAccept.Size = new System.Drawing.Size(125, 38);
            this.CreateAccept.TabIndex = 4;
            this.CreateAccept.Text = "生成";
            this.CreateAccept.UseVisualStyleBackColor = true;
            this.CreateAccept.Click += new System.EventHandler(this.CreateAccept_Click);
            // 
            // ValueData
            // 
            this.ValueData.AllowUserToAddRows = false;
            this.ValueData.AllowUserToDeleteRows = false;
            this.ValueData.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.ValueData.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.type,
            this.value});
            this.ValueData.Location = new System.Drawing.Point(470, 158);
            this.ValueData.Name = "ValueData";
            this.ValueData.RowTemplate.Height = 24;
            this.ValueData.Size = new System.Drawing.Size(452, 394);
            this.ValueData.TabIndex = 3;
            this.ValueData.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellContentClick);
            this.ValueData.CellEndEdit += new System.Windows.Forms.DataGridViewCellEventHandler(this.ValueData_CellEndEdit);
            // 
            // type
            // 
            this.type.HeaderText = "Type";
            this.type.Name = "type";
            this.type.ReadOnly = true;
            this.type.Resizable = System.Windows.Forms.DataGridViewTriState.True;
            // 
            // value
            // 
            this.value.HeaderText = "Value";
            this.value.Name = "value";
            // 
            // SelectedClass
            // 
            this.SelectedClass.AutoSize = true;
            this.SelectedClass.Location = new System.Drawing.Point(17, 573);
            this.SelectedClass.Name = "SelectedClass";
            this.SelectedClass.Size = new System.Drawing.Size(43, 15);
            this.SelectedClass.TabIndex = 2;
            this.SelectedClass.Text = "label1";
            // 
            // ClassMenberSelect
            // 
            this.ClassMenberSelect.FormattingEnabled = true;
            this.ClassMenberSelect.ItemHeight = 15;
            this.ClassMenberSelect.Location = new System.Drawing.Point(20, 158);
            this.ClassMenberSelect.Name = "ClassMenberSelect";
            this.ClassMenberSelect.Size = new System.Drawing.Size(415, 394);
            this.ClassMenberSelect.TabIndex = 1;
            this.ClassMenberSelect.SelectedIndexChanged += new System.EventHandler(this.ClassMenberSelect_SelectedIndexChanged);
            // 
            // RegistedClassSelect
            // 
            this.RegistedClassSelect.FormattingEnabled = true;
            this.RegistedClassSelect.ItemHeight = 15;
            this.RegistedClassSelect.Location = new System.Drawing.Point(20, 16);
            this.RegistedClassSelect.Name = "RegistedClassSelect";
            this.RegistedClassSelect.Size = new System.Drawing.Size(902, 124);
            this.RegistedClassSelect.TabIndex = 0;
            this.RegistedClassSelect.SelectedIndexChanged += new System.EventHandler(this.listBox1_SelectedIndexChanged);
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add(this.ModifyAccept);
            this.tabPage3.Controls.Add(this.ValueData_Modify);
            this.tabPage3.Controls.Add(this.ClassMenberSelect_Modify);
            this.tabPage3.Controls.Add(this.RegistedClassSelect_Modify);
            this.tabPage3.Controls.Add(this.SelectModify);
            this.tabPage3.Controls.Add(this.ModifySelect);
            this.tabPage3.Location = new System.Drawing.Point(4, 25);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage3.Size = new System.Drawing.Size(945, 615);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "Modify";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // ModifyAccept
            // 
            this.ModifyAccept.Location = new System.Drawing.Point(817, 542);
            this.ModifyAccept.Name = "ModifyAccept";
            this.ModifyAccept.Size = new System.Drawing.Size(96, 39);
            this.ModifyAccept.TabIndex = 5;
            this.ModifyAccept.Text = "更新";
            this.ModifyAccept.UseVisualStyleBackColor = true;
            this.ModifyAccept.Click += new System.EventHandler(this.ModifyAccept_Click);
            // 
            // ValueData_Modify
            // 
            this.ValueData_Modify.AllowUserToAddRows = false;
            this.ValueData_Modify.AllowUserToDeleteRows = false;
            this.ValueData_Modify.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.ValueData_Modify.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.ModifyType,
            this.ModifyValue});
            this.ValueData_Modify.Location = new System.Drawing.Point(436, 184);
            this.ValueData_Modify.Name = "ValueData_Modify";
            this.ValueData_Modify.RowTemplate.Height = 24;
            this.ValueData_Modify.Size = new System.Drawing.Size(477, 352);
            this.ValueData_Modify.TabIndex = 4;
            this.ValueData_Modify.CellEndEdit += new System.Windows.Forms.DataGridViewCellEventHandler(this.ValueData_Modify_CellEndEdit);
            // 
            // ModifyType
            // 
            this.ModifyType.HeaderText = "ModifyType";
            this.ModifyType.Name = "ModifyType";
            this.ModifyType.ReadOnly = true;
            // 
            // ModifyValue
            // 
            this.ModifyValue.HeaderText = "ModifyValue";
            this.ModifyValue.Name = "ModifyValue";
            // 
            // ClassMenberSelect_Modify
            // 
            this.ClassMenberSelect_Modify.FormattingEnabled = true;
            this.ClassMenberSelect_Modify.ItemHeight = 15;
            this.ClassMenberSelect_Modify.Location = new System.Drawing.Point(42, 184);
            this.ClassMenberSelect_Modify.Name = "ClassMenberSelect_Modify";
            this.ClassMenberSelect_Modify.Size = new System.Drawing.Size(348, 379);
            this.ClassMenberSelect_Modify.TabIndex = 3;
            this.ClassMenberSelect_Modify.SelectedIndexChanged += new System.EventHandler(this.ClassMenberSelect_Modify_SelectedIndexChanged);
            // 
            // RegistedClassSelect_Modify
            // 
            this.RegistedClassSelect_Modify.FormattingEnabled = true;
            this.RegistedClassSelect_Modify.ItemHeight = 15;
            this.RegistedClassSelect_Modify.Location = new System.Drawing.Point(42, 74);
            this.RegistedClassSelect_Modify.Name = "RegistedClassSelect_Modify";
            this.RegistedClassSelect_Modify.Size = new System.Drawing.Size(871, 94);
            this.RegistedClassSelect_Modify.TabIndex = 2;
            this.RegistedClassSelect_Modify.SelectedIndexChanged += new System.EventHandler(this.RegistedClassSelect_Modify_SelectedIndexChanged);
            // 
            // SelectModify
            // 
            this.SelectModify.AutoSize = true;
            this.SelectModify.Location = new System.Drawing.Point(180, 35);
            this.SelectModify.Name = "SelectModify";
            this.SelectModify.Size = new System.Drawing.Size(43, 15);
            this.SelectModify.TabIndex = 1;
            this.SelectModify.Text = "label1";
            // 
            // ModifySelect
            // 
            this.ModifySelect.Location = new System.Drawing.Point(42, 26);
            this.ModifySelect.Name = "ModifySelect";
            this.ModifySelect.Size = new System.Drawing.Size(122, 33);
            this.ModifySelect.TabIndex = 0;
            this.ModifySelect.Text = "更新ファイル選択";
            this.ModifySelect.UseVisualStyleBackColor = true;
            this.ModifySelect.Click += new System.EventHandler(this.ModifySelect_Click);
            // 
            // Main
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(978, 669);
            this.Controls.Add(this.tabControl1);
            this.Name = "Main";
            this.Text = "ScriptableObjectEditor";
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.ValueData)).EndInit();
            this.tabPage3.ResumeLayout(false);
            this.tabPage3.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.ValueData_Modify)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.Button RegisterAccept;
        private System.Windows.Forms.Button RegistClassSelectButton;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.Label SelectedClass;
        private System.Windows.Forms.Button CreateAccept;
        private System.Windows.Forms.Button ModifyAccept;
        private System.Windows.Forms.Button ModifySelect;
        private System.Windows.Forms.DataGridViewTextBoxColumn ModifyType;
        private System.Windows.Forms.DataGridViewTextBoxColumn ModifyValue;
        private System.Windows.Forms.DataGridViewTextBoxColumn type;
        private System.Windows.Forms.DataGridViewTextBoxColumn value;
        public System.Windows.Forms.ListBox RegistedClassSelect;
        public System.Windows.Forms.Label SelectClassName;
        public System.Windows.Forms.ListView ClassStructVeiw;
        public System.Windows.Forms.ListBox ClassMenberSelect;
        public System.Windows.Forms.DataGridView ValueData;
        public System.Windows.Forms.Label SelectModify;
        public System.Windows.Forms.ListBox RegistedClassSelect_Modify;
        public System.Windows.Forms.ListBox ClassMenberSelect_Modify;
        public System.Windows.Forms.DataGridView ValueData_Modify;
    }
}

