#include <iostream>
#include <string>
using namespace std;

//1. Khai báo cấu trúc của danh sách liên kết. Các thông tin chứa ở mỗi node là 1 file tự đưa vào để đảm bảo các nội dung sau được thực hiện

//mieu ta file gom cos gi


struct thoigian {
	int ngay, thang, nam, gio, phut, giay;
};

struct file {
	string tenfile;
	long long kichthuocfile;
	thoigian thoigianluufile;
};

struct nodefile {
	file data;
	nodefile* nextfile;

};

struct danhsachfile {
	nodefile* filedau = nullptr; 
};

//2. Copy paste một file từ thư mục khác sang thư mục trên sao cho file luôn được chèn vào theo trật tự thời gian.
// ham so sanh trat tu thoi gian
bool sosanhthoigianluufile(thoigian time1, thoigian time2)  // tra ve true khi ma file1 duoc luu som hon file 2 
{
	if (time1.nam < time2.nam) return true;
	else if (time1.nam > time2.nam) return false;

	if (time1.thang < time2.thang) return true;
	else if (time1.thang > time2.thang) return false;

	if (time1.ngay < time2.ngay) return true;
	else if (time1.ngay > time2.ngay) return false;

	if (time1.gio < time2.gio) return true;
	else if (time1.gio > time2.gio) return false;

	if (time1.phut < time2.phut) return true;
	else if (time1.phut > time2.phut) return false;

	if (time1.giay < time2.giay) return true;
	else if (time1.giay > time2.giay) return false;

	return false;

}
// ham sao chep file vào danh sách
void saochepfile(danhsachfile& ds, file filemoi)
{
	nodefile* nodemoi = new nodefile;
	nodemoi->data = filemoi;
	nodemoi->nextfile = nullptr;

	// th1: Danh sách rỗng or file mới có thời gian sớm hơn file đầu tiên

	if (ds.filedau == nullptr || sosanhthoigianluufile(filemoi.thoigianluufile, ds.filedau->data.thoigianluufile))
	{
		nodemoi->nextfile = ds.filedau;
		ds.filedau = nodemoi;
		return;
	}
	//th2 : Tìm vị trí để chèn vào giữa hoặc cuối danh sách
	nodefile* nodehientai = ds.filedau;
	while (nodehientai->nextfile == nullptr || sosanhthoigianluufile(filemoi.thoigianluufile, nodehientai->nextfile->data.thoigianluufile))
	{
		nodemoi->nextfile = nodehientai->nextfile;
		nodehientai->nextfile = nodemoi;
		return;
	}
}

//3.  hàm tính toán kích thước các file 
long long tongkichthuocfile(danhsachfile ds)
{
	long long count = 0;
	nodefile* nodehientai = ds.filedau;
	while (nodehientai != nullptr)
	{
		count += nodehientai->data.kichthuocfile;
		nodehientai = nodehientai->nextfile;
	}
	return count;
}

// hàm main
int main()
{
	danhsachfile ds;
	file file1 = { "kichbanmonkinangmem.docs", 29, {31, 03, 2026, 20, 56, 0} };
	file file2 = { "tkb20252.xlsx", 28, {9, 01, 2026, 20, 8, 59} };
	file file3 = { "caukiendientu.docs", 199, {22, 02, 2026, 7, 58, 0} };
	saochepfile(ds, file1);
	saochepfile(ds, file2);	
	saochepfile(ds, file3);

	cout << "Danh sach file trong thu muc (theo thoi gian): " << endl;
	xuatDanhSach(ds);
	cout << endl;
	cout << "Tong kich thuoc: " << tongkichthuocfile(ds) << " bytes" << endl;

	return 0;
}



