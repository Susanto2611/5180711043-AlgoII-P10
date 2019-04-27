#include <windows.h>
#include <conio.h>
#include <iostream>
#include <stdio.h>

using namespace::std;


struct data
    {
    int seri;
    char judul[100];
    int rak;
    };


data buku[100];
data temp;
int a;
int jml;


void prolog()
    {
        cout<<" =============================================\n";
        cout<<"          PENDATAAN BUKU TEKNIK ELEKTRO\n";
        cout<<"                  PERPUSTAKAAN\n";
        cout<<"        UNIVERSITAS TEKNOLOGI YOGYAKARTA\n";
        cout<<" =============================================\n";
    }


void eksekusi()
    {
        cout<<"\n =============================================\n";
        cout<<" |             Eksekusi Program              |\n";
        cout<<" ---------------------------------------------\n";
        cout<<" |   Code   |            Prosedur            |\n";
        cout<<" |    1     |         Hapus Data             |\n";
        cout<<" |    2     |         Edit Data              |\n";
        cout<<" |    3     |         Sorting                |\n";
        cout<<" |    4     |         Cari Data              |\n";
        cout<<" |    5     |         Status Data            |\n";
        cout<<" |    6     |         Exit                   |\n";

        cout<<" =============================================\n";
    }


void prosedur_status()
    {
        prolog();
        int i;
            cout<<"                 STATUS DATA\n";
            cout<<" =============================================\n";
            for(i=0;i<jml;i++)
                {
                    cout<<"\n =============================================\n";
                    cout<<" Data Buku ke- "<<i+1;
                    cout<<"\n ---------------------------------------------\n";
                    cout<<" No. Seri Buku\t: "<<buku[i].seri;
                    cout<<"\n Judul Buku\t: "<<buku[i].judul;
                    cout<<"\n Letak Buku\t: Lemari "<<buku[i].rak<<endl;
                }
            cout<<"\n ---------------------------------------------\n";
    }


void prosedur_hapus()
    {

        prolog();
        int x,y;
            cout<<"               PROSEDUR HAPUS DATA\n";
            cout<<" =============================================\n";
            cout<<" Hapus Data ke\t:";cin>>x;
            y=x-1;
            jml--;
            for(int i=y;i<jml;i++)
                {
                    buku[i]=buku[i+1];
                }
            cout<<" =============================================\n";
            cout<<"                 Data Terhapus \n";
            cout<<" =============================================\n";
    }


void prosedur_edit()
    {
        prolog();
        int k,h;
            cout<<"              PROSEDUR EDIT DATA\n";
            cout<<" =============================================\n";
            cout<<" Edit Data ke\t: ";cin>>k;
            h=k-1;
            cout<<" =============================================\n";
            cout<<" NB: *gunakan underscore (judul_buku)\n";
            cout<<" No. Seri Buku\t: ";cin>>buku[h].seri;
            cout<<" Judul Buku*\t: ";cin>>buku[h].judul;
            cout<<" Letak Buku\t: ";cin>>buku[h].rak;
            cout<<" =============================================\n";
            cout<<"             DATA BERHASIL DIUBAH\n";
            cout<<" =============================================\n";
    }

void prosedur_sorting()
{
    int r,u;

                for(r=0;r<jml;r++)
                {
                    for(u=0;u<jml-1;u++)
                        {
                            if(buku[u].seri > buku[u+1].seri)
                                {
                                     temp.seri=buku[u].seri;
                                     buku[u].seri=buku[u+1].seri;
                                     buku[u+1].seri=temp.seri;

                                     strcpy(temp.judul,buku[u].judul);
                                     strcpy(buku[u].judul,buku[u+1].judul);
                                     strcpy(buku[u+1].judul,temp.judul);

                                     temp.rak=buku[u].rak;
                                     buku[u].rak=buku[u+1].rak;
                                     buku[u+1].rak=temp.rak;
                                }
                        }
                }

            prolog();

            cout<<"              PROSEDUR SORTING DATA\n";
            cout<<" =============================================\n";

            for(u=0;u<jml;u++)
                {
                    cout<<"\n =============================================\n";
                    cout<<" Data Buku ke- "<<u+1;
                    cout<<"\n ---------------------------------------------\n";
                    cout<<"\n No. Seri Buku\t: "<<buku[u].seri;
                    cout<<"\n Judul Buku\t: "<<buku[u].judul;
                    cout<<"\n Letak Buku\t: Lemari "<<buku[u].rak<<endl;
                }
            cout<<"\n ---------------------------------------------\n";

}

void prosedur_search()
{
    int indeks;
    char cari;
    int cari_seri;
    string cari_judul;
    bool status=false;
    prolog();
    cari_data:
    cout<<"                 PENCARIAN BUKU\n";
    cout<<" =============================================\n";
    cout<<" |   Code   |       Cari Berdasarkan         |\n";
    cout<<" |    A     |     No. Seri Buku              |\n";
    cout<<" |    B     |     Judul Buku                 |\n";
    cout<<" =============================================\n";
    cout<<" Masukan Code Pencarian: ";cin>>cari;
system("CLS");
    switch (cari)
    {

    case 'A' :
                prolog();
                cout<<"\n Inputkan No. Seri Buku\t: ";cin>>cari_seri;
                    for (int i=0;i<jml;i++)
                        {
                            if (cari_seri == buku[i].seri)
                                {
                                    status = true;
                                    indeks = i;
                                }

                        }

                 if (status)
                    {
                        cout<<" =============================================\n";
                        cout<<"                BUKU TERSEDIA\n";
                        cout<<" ---------------------------------------------\n";
                        cout<<" Judul Buku\t: "<<buku[indeks].judul;
                        cout<<"\n No. Seri Buku\t: "<<buku[indeks].seri;
                        cout<<"\n Letak Buku\t: Lemari "<<buku[indeks].rak;
                        cout<<"\n ---------------------------------------------\n";
                    }
                 else
                    {
                        cout<<" =============================================\n";
                        cout<<"             BUKU TIDAK DITEMUKAN";
                        cout<<"\n =============================================\n";
                    }
                    break;


    case 'B' :
                prolog();
                cout<<" NB: *gunakan underscore (judul_buku)\n";
                cout<<"\n Inputkan Judul Buku\t: ";cin>>cari_judul;
                    for (int i=0;i<jml;i++)
                        {
                            if (cari_judul == buku[i].judul)
                                {
                                    status = true;
                                    indeks = i;
                                }

                        }

                 if (status)
                    {
                        cout<<" =============================================\n";
                        cout<<"                BUKU TERSEDIA\n";
                        cout<<" ---------------------------------------------\n";
                        cout<<" Judul Buku\t: "<<buku[indeks].judul;
                        cout<<"\n No. Seri Buku\t: "<<buku[indeks].seri;
                        cout<<"\n Letak Buku\t: Lemari "<<buku[indeks].rak;
                        cout<<"\n ---------------------------------------------\n";
                    }
                 else
                    {
                        cout<<" =============================================\n";
                        cout<<"             BUKU TIDAK DITEMUKAN";
                        cout<<"\n =============================================\n";
                    }
                break;

    default:
                prolog();
                cout<<"                CODE TIDAK SESUAI";
                cout<<"\n =============================================\n";
                goto cari_data; break;
    }

}


int main()
{
cout<<"\n\n";

    prolog();

    int code;
    int c;

  cout<<"\n Input Jumlah Data Buku: ";cin>>jml;

system("CLS");
  prolog();
  cout<<"                 INPUT DATA\n";
  cout<<" =============================================\n";
  cout<<" NB: *gunakan underscore (judul_buku)\n";
  for(c=0;c<jml;c++)
    {
          cout<<"\n Data Buku ke-"<<c+1<<endl;
          cout<<" No. Seri\t: ";cin>>buku[c].seri;
          cout<<" Judul Buku*\t: ";cin>>buku[c].judul;
          cout<<" Lemari Buku\t: ";cin>>buku[c].rak;
    }

system("CLS");

    awal:
    prolog();
    eksekusi();

  cout<<" INPUT CODE\t: ";cin>>code;

system("CLS");
    if(code==1)
        {
            prosedur_hapus();getch();system("CLS");goto awal;
        }
    if(code==2)
        {
            prosedur_edit();getch();system("CLS");goto awal;
        }
    if(code==3)
        {
            prosedur_sorting();getch();system("CLS");goto awal;
        }
    if(code==4)
        {
            prosedur_search();getch();system("CLS");goto awal;
        }
    if (code==5)
        {
            prosedur_status();getch();system("CLS");goto awal;
        }
    if(code==6)
        {
            goto exit;
        }
    else
        {
            goto awal;
        }



exit:
            cout<<"\n\n\n\n\n";
            cout<<"           =============================================\n";
            cout<<"                TEKAN TOMBOL APA SAJA UNTUK KELUAR\n";
            cout<<"           =============================================\n";
            cout<<"\n\n\n\n\n";


cout<<"\n\n\n";
return 0;
}



