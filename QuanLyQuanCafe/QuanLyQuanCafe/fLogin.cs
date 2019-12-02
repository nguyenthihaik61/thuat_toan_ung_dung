using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace QuanLyQuanCafe
{
    public partial class fLogin : Form
    {
        public fLogin()
        {
            InitializeComponent();
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            Application.Exit();//Thoat chuong trinh khi click vao button thoat
        }

        private void fLogin_FormClosing(object sender, FormClosingEventArgs e)
        {
            if(MessageBox.Show("Ban co muon thoat chuong trinh?","Thong bao",MessageBoxButtons.OKCancel)!= System.Windows.Forms.DialogResult.OK)
            {
                e.Cancel=true;
            }
        }

        private void btnLogin_Click(object sender, EventArgs e)
        {
            this.Hide();
            fTableManager f = new fTableManager();
            f.ShowDialog();
            this.Show();
        }
    }
}
