#include <iostream>
using namespace std;
int main()
{
    cout<<"masukkan norek anda: ";          //untuk memasukkan no rekening
    int validasi,valid,validasi2,valid2;    //menentukan tipe data
    long long norek,mods, dive;             //tipe data long long digunakan dikarenakan ketiga data tersebut akan melebihi nilai max dari int yaitu 2,147,483,647
    cin>>norek;                             
    mods=100;                               //menetapkan niali mods menjadi 100
    dive=10;                                //menetapkan nilai mods menjadi 10
    validasi=0;                             //menetapkan nilai validasi menjadi 0
    do                                      //melakukan pengulangan untuk menyeleksi angka ke 2 dari belakang lalu dikelang 1 sampai angka terdepan
    {
        valid= (((norek%mods)/ dive)*2);    //untuk memilih angka ke 2 dari belakang lalu di kalikan 2
        if (valid>=10|| valid <0)           //untuk menyeleksi angka yang lebih dari 2 digit, jika lebih dari 2 digit angka akan dipisah lalu ditambahkan
            {
                int angka_1, angka_2;
                angka_1= valid % 10;               
                angka_2= valid / 10;                          
                valid = angka_1+angka_2;
            } 
            else
            {
                valid= valid;

            }
        validasi=validasi +valid;           //setelah angka didapatkan,angka akan ditambahkan ke total dari seluruh angka
        mods*=100;                          //mods dikali 100 dan div dikali 100 untuk mengubah maju 2 kedepan yang  dari norek.
        dive*=100;
    } while ((mods<=10000000000000000)||(dive<=1000000000000000)); // pengulangan ini akan terus dilakukan mods dan dive sudan mencapai angka tersebut atau sudah sampai angka terdepan dari norek

    mods=10; //mods dan dive ditetapkan kembali karena nilai yang sudah tinggi
    dive=1;
    validasi2=0; //validasi2 di ditetapkan
    do              // melakukan pengulangan untuk mengambil angka paling belakang dan dikelang 1 hingga angka terdepan 
    {
        valid2= ((norek%mods)/ dive); //untuk menyisakan angka yang dipilih dari norek
        validasi2=validasi2+valid2;     //menambahkan angka yang didapat dari seluruh total angka yang dipilih
        mods*=100;                      //setelah angka didapat mods dan dive dikalikan 100 untuk memajukan angka yang akan diambil
        dive*=100;
    } while ((mods<=1000000000000000)||(dive<=100000000000000)); // pengulangan ini akan terus dilakukan mods dan dive sudan mencapai angka tersebut

    int valtol= validasi+validasi2; //berfungsi untuk menambahkan hasil angka yang dikalikan dan angka yang tidak dikalikan

    string vld;     //menetapkan tipe data string pada vld
    if ((((norek%10000000000000000)/1000000000000000)==5)&&(valtol% 10== 0))    //if digunakan untuk menyeleksi apakah kartu tersebut mastercard, visa atau tidak valid
    {
        vld="MASTERCARD";
    }
    else if((((norek%10000000000000000)/1000000000000000)==4)&&(valtol% 10==0))
    {
        vld="VISA";
    }
    else
    {
        vld="tidak valid";
    }
    cout<<"nomor kartu anda :"<< norek<<endl; //untuk melakukan output dari nomor kartu, tipe kartu dan checksum
    cout<<"tipe kartu anda :"<< vld <<endl;
    cout<<"checksum: "<<valtol<<endl;

    return 0;

}