#include<conio.h>
#include<stdio.h>
#include <iostream>
#include <string.h>
#define MAX 100
using namespace std;

struct KhachHang
{
    int id;
   char ten[30];
   char gioitinh[5];
   int tuoi;
   float cmt;
   char diachi[30];
    float NgayThue;
   float NgayTra;
   float giathue;
   float sotien; 
   char LoaiXe[30];
   float SoDKXe;
   char TinhTrangXe[30];
   float tienthue = 0;
};

typedef KhachHang KH;

void printLine(int n);
void NhapThongTinKH(KH & kh, int id);
void NhapKH(KH a[], int id, int n);
void CapNhapThongTinKH(KH & kh);
void CapNhapKH(KH a[], int id, int n);
int xoaTheoID(KH a[], int id, int n);
void timkiemtheoten(KH a[], char ten[], int n);
void tinhtienthue(KH &kh);
int idlonnhat(KH a[], int n);
void sapxeptheotienthue(KH a[], int n);
void sapxeptheoten(KH a[], int n);
void showKhachhang(KH a[], int n);
int docFile(KH a[], char fileName[]);
void ghiFile(KH a[], int n, char fileName[]);
void pressAnyKey();

int main(){
    int key;
    char fileName[] = "KH.txt";
    KH arrayKH[MAX];
    int soluongKH=0;
    int idCount = 0;

    soluongKH = docFile(arrayKH, fileName);
    idCount = idlonnhat(arrayKH, soluongKH);

     while (true)
    {
	    cout<<"\n\n\n\t\t\t================ CHUONG TRINH QUAN LY KHACH HANG THUE XE OTO ==================";
		   	cout <<"\n\n\t\t\t  1. Them Khach Hang "; 
			cout <<"\n\t\t\t  2. Cap nhap thong tin Khach hang ";
	     	cout <<"\n\t\t\t  3. Xoa kahch hang ";
			cout <<"\n\t\t\t  4. Tim kiem khach hang theo ten "; 
			cout <<"\n\t\t\t  5. Sap xep khach hang theo gia thue ";  
			cout <<"\n\t\t\t  6. Sap xep Khach hang theo ten";
			cout <<"\n\t\t\t  7. Hien thi danh sach khach hang";
            cout <<"\n\t\t\t  8. Ghi danh sach Khach hang vao File";
            cout <<"\n\t\t\t  9. Tong gia tien thue";
			cout <<"\n\t\t\t  0. Thoat ";
			cout<<"\n\n\n\t\t\t=================================== END ======================================";
		   cout<<"";
		   cout<< "\n\n\t\t\t Nhap tuy chon: ";
        cin >> key;
      switch (key)
      {
      case 1:
      cout <<"\n1. Them Khach hang.";
      idCount++;
      NhapKH(arrayKH,idCount, soluongKH);
      printf("\n them khach hang thanh cong");
      soluongKH++;
      pressAnyKey();
        break;

      case 2:
      if(soluongKH > 0){
          int id;
          cout <<"\n2. Cap nhap thong tin Khach hang";
          cout <<"\n Nhap ID: "; cin >>id;
          CapNhapKH(arrayKH, id, soluongKH);
      }else{
          cout <<"\n Danh sach khach hang trong";
      }
      pressAnyKey();
      break;

      case 3:
      if(soluongKH > 0){
          int id; 
          cout <<"\n3. Xoa Khach Hang";
          cout <<"\n Nhap id:"; cin >> id;
          if(xoaTheoID(arrayKH, id, soluongKH)==1){
              printf("\n Khach hang co id = %d da bi xoa.", &id);
              soluongKH--;
          }
      }else{
                    cout << "\ndanh sach Khach hang trong!";
                }
                pressAnyKey();
                break;


       case 4:
       if(soluongKH > 0){
           cout <<"\n4. Tim kiem khach hang theo ten.";
           char strTen[30];
           cout <<"\n Nhap ten Khach Hang de tim kiem: "; fflush(stdin); gets(strTen);
           timkiemtheoten(arrayKH, strTen, soluongKH);

       }else{
           cout <<"\nDanh sach Khach Hang trong";
       }
       pressAnyKey();
       break;

       case 5: 
       if(soluongKH > 0){
           cout <<"\n5. Sap xep Khach Hang theo Gia thue ";
           sapxeptheotienthue(arrayKH, soluongKH);
           showKhachhang(arrayKH, soluongKH);

           
       }else{
           cout<<"\n Danh sanh Khach Hang trong";
       }
       pressAnyKey();
       break;

       case 6:
       if(soluongKH > 0){
           cout <<"\n6. Sap xep Khach hang theo Ten";
           sapxeptheoten(arrayKH, soluongKH);
           showKhachhang(arrayKH, soluongKH);

       }else{
           cout<<"/n Danh sach khach hang trong";
       }
       pressAnyKey();
       break;

       case 7:
       if(soluongKH > 0){
           cout <<"\n7. Hien thi danh sach khach hang.";
           showKhachhang(arrayKH, soluongKH);
       }else{
           cout <<"\n Danh sach khach hang trong";
       }
       pressAnyKey();
       break;


       case 8:
       if(soluongKH > 0){
           cout <<"\n8. Ghi danh sah khach hang vao file";
           ghiFile(arrayKH, soluongKH, fileName);
       }else{
           cout<<"\n Danh sanh khach hang trong";
       }
       printf("\n Ghi danh sanh thanh cong");
       pressAnyKey();
       break;
       
       case 9:
       	if(soluongKH > 0){
       		cout <<"\n9. Tong gia tien thue";
       		void tinhtienthue(KH &kh);
       		
		   }else{
           cout<<"\n Danh sanh khach hang trong";
       }
        getch();
       return 0;

       case 0:
       cout<<"\n Ban da chon thoat chuong trinh";
       getch();
       return 0;

       default:
       cout << "\nKhong co chuc nang nay!";
                cout << "\nHay chon chuc nang trong hop menu.";
                pressAnyKey();
                break;
       }
    }
}

void tinhtienthue(KH &kh){
    kh.tienthue= (kh.sotien * kh.tienthue);
}
void NhapThongTinKH(KH & kh, int id){
    cout <<"\n Nhap ten: "; fflush(stdin); gets(kh.ten);
    cout <<"\n Nhap gioi tinh: "; gets(kh.gioitinh);
    cout <<"\n Nhap tuoi: "; cin >> kh.tuoi;
    cout <<"\n Nhap CMND: "; cin>> kh.cmt;
    cout <<"\n Nhap dia chi: "; fflush(stdin); gets(kh.diachi);
    cout <<"\n Nhap Ngay thue: "; cin>> kh.NgayThue;
    cout <<"\n Nhap Ngay tra: "; cin>> kh.NgayTra;
    cout <<"\n Nhap gia thue: "; cin>> kh.giathue;
    cout <<"\n Nhap so tien : "; cin>> kh.sotien;
    cout <<"\n Nhap loai xe: "; fflush(stdin); gets(kh.LoaiXe);
    cout <<"\n Nhap so dang ky xe: "; cin>> kh.SoDKXe;
    cout <<"\n Tinh trang xe: "; fflush(stdin); gets(kh.TinhTrangXe);

    kh.id = id;
    tinhtienthue(kh);

}
void NhapKH(KH a[], int id, int n){
    printLine(40);
    printf("\n Nhap Khach hang thu %d: ", n+1);
    NhapThongTinKH(a[n], id);
    printLine(40);

}
void CapNhapThongTinKH(KH & kh){
     cout <<"\n Nhap ten: "; fflush(stdin); gets(kh.ten);
    cout <<"\n Nhap gioi tinh: "; gets(kh.gioitinh);
    cout <<"\n Nhap tuoi: "; cin >> kh.tuoi;
    cout <<"\n Nhap CMND: "; cin>> kh.cmt;
    cout <<"\n Nhap dia chi: "; fflush(stdin); gets(kh.diachi);
    cout <<"\n Nhap Ngay thue: "; cin>> kh.NgayThue;
    cout <<"\n Nhap Ngay tra: "; cin>> kh.NgayTra;
    cout <<"\n Nhap gia thue: "; cin>> kh.giathue;
    cout <<"\n Nhap so tien : "; cin>> kh.sotien;
    cout <<"\n Nhap loai xe: "; fflush(stdin); gets(kh.LoaiXe);
    cout <<"\n Nhap so dang ky xe: "; cin>> kh.SoDKXe;
    cout <<"\n Tinh trang xe: "; fflush(stdin); gets(kh.TinhTrangXe);

    tinhtienthue(kh);

}
void CapNhapKH(KH a[], int id, int n){
    int found = 0;
    for (int i = 0; i < n; i++){
        if(a[i].id == id){
            found = 1;
            printLine(40);
            cout<<"\n cap nhap thong tin khach hang co Id: "<< id;
            CapNhapThongTinKH(a[i]);
            printLine(40);
            break;
        }   
    }
    if(found == 0){
            printf("\n Khach hang co id = %d khog ton tai");
    }
    
}

int xoaTheoID(KH a[], int id, int n){
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (a[i].id == id) {
            found = 1;
            printLine(40);
            for (int j = i; j < n; j++) {
                a[j] = a[j+1];
            }
            cout << "\n Da xoa Kh co ID = " << id;
            printLine(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n Khach hang co ID = %d khong ton tai.", id);
        return 0;
    } else {
        return 1;
    }
}

void timkiemtheoten(KH a[], char ten[], int n){
    KH arrayFound[MAX];
    char TenKH[30];
    int found = 0;
    for(int i =0; i < n; i++){
        strcpy(TenKH, a[i].ten);
        if(strstr(strupr(TenKH), strupr(ten))){
            arrayFound[found]=a[i];
            found++;
        }
    }
    showKhachhang(arrayFound, found);
}
void showKhachhang(KH a[], int n){
    printLine(100);
    cout <<"\n\STT\tID\tHo Va Ten\tGioi Tinh\tTuoi\tCMND\tDia chi\tNgay Thue\tNgay tra\tGia thue\tSo Tien\tLoai Xe\tSo Dang Ky Xe\tTinh Trang Xe";
    for(int i=0; i<n; i++){
        printf("\n%d", i+1);
        printf("\t%d", a[i].id);
        printf("\t%s",a[i].ten);
        printf("\t\t%s", a[i].gioitinh);
        printf("\t\t%d",a[i].tuoi);
        printf("\t%.2f", a[i].cmt);
         printf("\t\t%s", a[i].diachi);
        printf("\t%.2f",a[i].NgayThue);
        printf("\t%.2f",a[i].NgayTra);
        printf("\t%.2f", a[i].giathue);
        printf("\t%.2f", a[i].sotien);
        printf("\t\t%s",a[i].LoaiXe);
        printf("\t%.2f", a[i].SoDKXe);
         printf("\t\t%s", a[i].TinhTrangXe);
      
    }
    printLine(100);
}

void sapxeptheotienthue(KH a[], int n){
    KH tmp;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(a[i].tienthue > a[j].tienthue){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}
void sapxeptheoten(KH a[], int n){
    KH tmp;
    char tenKH1[30];
    char tenKH2[30];
    for (int i= 0; i < n; i++){
        strcpy(tenKH1, a[i].ten);
        for(int j = i+1; j < n; j++){
            strcpy(tenKH2, a[j].ten);
        if(strcmp(strupr(tenKH1), strupr(tenKH2)) > 0){
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;

        }
    }
  }
}

int idlonnhat(KH a[], int n){
    int idMax = 0;
    if(n > 0){
        idMax = a[0].id;
        for(int i = 0; i<n; i++){
            if(a[i].id > idMax){
                idMax = a[i].id;
            }
        }
    }
    return idMax;
}
int docFile(KH a[], char fileName[]){
    FILE * fp;
    int i = 0;
    fp = fopen (fileName, "r");
    cout <<"Chuan bi doc file: "; puts(fileName);

    while (fscanf(fp, "%5d%30s%5s%5d%10f%10s%10f%10f%10f%10f%10s%10f%10s\n", a[i].id, &a[i].ten, &a[i].gioitinh, &a[i].tuoi, &a[i].cmt, &a[i].diachi,&a[i].NgayThue,&a[i].NgayTra,&a[i].giathue, &a[i].sotien,&a[i].LoaiXe,&a[i].SoDKXe,&a[i].TinhTrangXe)!=EOF){    
    i++;
    cout <<" Doc ban ghi thu: "<< i <<endl;
    
    }
    cout << "So luong khach hang co tron file la: "<< i <<endl;
    cout << endl;
    fclose(fp);

    return i;
   
    
}
void ghiFile(KH a[], int n, char fileName[]){
    FILE * fp;
    fp = fopen (fileName, "w");
    for(int i = 0; i<n; i++){
        fprintf(fp, "%5d%30s%5s%5d%10f%10s%10f%10f%10f%10f%10s%10f%10s\n", a[i].id, &a[i].ten, &a[i].gioitinh, &a[i].tuoi, &a[i].cmt, &a[i].diachi, &a[i].giathue, &a[i].sotien );

    }
    fclose(fp);
}

void printLine(int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "___";
    }
    cout << endl;
}
void pressAnyKey() {
    cout << "\n\nBam phim bat ky de tiep tuc...";
    getch();
    system("cls");
}













