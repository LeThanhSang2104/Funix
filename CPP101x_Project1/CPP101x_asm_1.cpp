
/*
    @file:
    @date time:
    @brief:
    Author: SangLT
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CPP101x_asm_1.h"
#include<iostream>
#include <string>

using namespace std;

/*================================================================================================*/
/**
* @brief     Login function.
* @details   Nhap vao ma so ca nhan, neu dung thi sang man hinh MH-2, sai thi nhap lai cho den khi dung
* @return
/*================================================================================================*/

void powerOff();
void login(void)
{
    do
    {
        cout << "NHAP MA SO CA NHAN: ";
        cin >> mscn;
        if (isNumber(mscn))
        {
            // Kiem tra ma so ca nhan nhap vao co dung hay khong. 
            // Neu dung sang man hinh MH-2

            if (mscn == MSCN)
            {
                Welcome();
            }

            // Sai yeu cau nhap lai
            else
            {
                cout << "Nhap lai cho den khi nhap dung ma so ca nhan" << endl;
            }
        }
        else
        {
            cout << "Can nhap vao ky tu tu 0 -> 9" << endl;
        }
    } while (mscn != MSCN);
}

/*================================================================================================*/
/**
* @brief     Welcome function.
* @details   Hien thi man hinh lua chon MH-2
/*================================================================================================*/
void Welcome(void)
{
    system("cls");
    cout << "XIN CHAO " << mscn << endl;
    ShowMenu();
}

/*================================================================================================*/
/**
* @brief     ShowMenu function.
* @details   Hien thi man hinh lua chon MH-2
/*================================================================================================*/
void ShowMenu(void)
{
    bool error; //Our error flag
    do
    {
        cout << "XIN MOI LUA CHON: " << endl;
        cout << " 1. P" << endl;                // Chuyen so sang so P, do va dung xe
        cout << " 2. R " << endl;               // Chuyen so sang so R, de lui xe
        cout << " 3. N " << endl;               // Chuyen so sang so N, tam dung xe
        cout << " 4. D " << endl;               // Chuyen so sang so D, tien xe
        cout << " 5. POWER OFF " << endl;       // Tat may dung hoat dong
        cout << ">>";
        cin >> luachon;
        
        if (( luachon < 1) || (luachon > 5))
        {
            cout << "Nhap vao so nguyen tu 1 - 5" << endl;
        }
        
        error = false;//Flag false, safe
        if (cin.fail())
        {
            error = true;//Flag true, error has occurred
            cout << "Invalid, Can nhap vao so nguyen" << endl;
            //system("cls");
        }
        cin.clear();                        //Clears any error flags
        cin.ignore(1000, '\n');              //Ignores 1000 characters, or until '\n'
    } while (error || (luachon < 1 || luachon > 5));
    switch (luachon) {
    case 1:
        ChonHanhTrinh_P();
        
        break;
    case 2:
        ChonHanhTrinh_R();
        
        break;
    case 3:
        ChonHanhTrinh_N();
        
        break;
    case 4:
        ChonHanhTrinh_D();
        break;
    case 5:
        powerOff();
        break;
    default:
        break;
    }
}
/*================================================================================================*/
/**
* @brief     ChonHanhTrinh_P_N function.
* @details   Chon che do P hoac N
/*================================================================================================*/
void ChonHanhTrinh_P(void)
{
    system("cls");
    bool error;//Our error flag
    do
    {
        error = false;//Flag false, safe
        cout << "Nhap toc do cua xe: ";
        cin >> tocdo;
        
        if (cin.fail())
        {
            error = true;//Flag true, error has occurred
            cout << "Invalid,Can nhap vao so nguyen" << endl;;
        }
        cin.clear();                        //Clears any error flags
        cin.ignore(1000, '\n');              //Ignores 1000 characters, or until '\n'
    } while (error);

    if (tocdo == 0)
    {
        system("cls");
        cout << "DA VE SO P " << endl;
        cout << "CHU Y SU DUNG PHANH TAY DE DAM BAO AN TOAN\n " << endl;
    }
    else
    {
        system("cls");
        cout << "HAY CHAC CHAN DA DUNG VA VAN TOC LA 0 KM/H\n " << endl;
    }
    check = 2;
    ShowMenu();
    
}

void ChonHanhTrinh_N(void)
{
    system("cls");
    bool error;//Our error flag
    do
    {
        error = false;//Flag false, safe
        cout << "Nhap toc do cua xe: ";
        cin >> tocdo;
        if (cin.fail())
        {
            error = true;//Flag true, error has occurred
            cout << "Invalid,Can nhap vao so nguyen\n\n";
            system("cls");
        }
        cin.clear();                        //Clears any error flags
        cin.ignore(1000, '\n');              //Ignores 1000 characters, or until '\n'
    } while (error);

    if (tocdo == 0)
    {
        system("cls");
        cout << "DA VE SO N " << endl;
        cout << "CHU Y SU DUNG PHANH TAY DE DAM BAO AN TOAN\n " << endl;
    }
    else
    {
        system("cls");
        cout << "HAY CHAC CHAN DA DUNG VA VAN TOC LA 0 KM/H\n " << endl;
    }
    check = 2;
    ShowMenu();

}

/*================================================================================================*/
/**
* @brief     ChonHanhTrinh_R_D function.
* @details   Chon che do R hoac D
/*================================================================================================*/
void ChonHanhTrinh_D(void)
{
    system("cls");
    
    if (check == 2)
    {
        tocdo = TOCDOMACDINH;
        cout << "---- TOC DO HIEN TAI: " << tocdo << " km/h" << endl;
        
    }
    if (checkR == 2)
    {
        if (tocdo != 0)
        {
            tocdo = 0;
            cout << "---- TOC DO HIEN TAI: " << tocdo << " km/h" << endl;
            cout << " CHI CHO PHEP CHUYEN SANG D KHI TOC DO = 0"  << endl;
        }
        else
        {
            tocdo = TOCDOMACDINH;
            cout << "---- TOC DO HIEN TAI: " << tocdo << " km/h" << endl;
            
        }
    }
    
    checkD = 4;
    check = 0;
    ShowMenu_R_D();
}

void ChonHanhTrinh_R(void)
{
    system("cls");
    if (check == 2)
    {
        tocdo = TOCDOMACDINH;
        cout << "---- TOC DO HIEN TAI: " << tocdo << " km/h" << endl;
        
    }
    if (checkD == 4)
    {
        if (tocdo != 0)
        {
            tocdo = 0;
            cout << "---- TOC DO HIEN TAI: " << tocdo << " km/h" << endl;
            cout << " CHI CHO PHEP CHUYEN SANG R KHI TOC DO = 0 "  << endl;
        } 
    }

    checkR = 2;
    check = 0;
    ShowMenu_R_D(); 
}

/*================================================================================================*/
/**
* @brief     ShowMenu_R_D function.
* @details   Show lua chon khi chon che do R hoac D
/*================================================================================================*/
void ShowMenu_R_D(void)
{
    bool error;//Our error flag
    do
    {
        //your code here
        cout << "MOI LUA CHON: " << endl;
        cout << " 1: TANG TOC" << endl;
        cout << " 2: GIAM TOC " << endl;
        cout << " 3: PHANH " << endl;
        cout << " 4: TRO VE MENU " << endl;
        cout << ">> ";
        cin >> luachon_R_D;
        error = false;                      //flag false
        if (cin.fail())
        {
            error = true;                   //flag true
            cout << "Invalid,Can nhap vao so nguyen\n\n";
            //system("cls");
        }
        cin.clear();                         //Clears flag error
        cin.ignore(1000, '\n');              //Ignores 1000 characters, or until '\n'
    } while (error || (luachon_R_D < 1 || luachon_R_D > 4));

    switch (luachon_R_D) {
    case 1:
        system("cls");
        tocdo = tocdo + 5;
        cout << "---- TOC DO HIEN TAI: " << tocdo << " km/h" << endl;
        CanhBao(tocdo);
        checkR = 2;
        checkD = 4;
        ShowMenu_R_D();
        break; 
    case 2:
        system("cls");
        do
        {
            tocdo = tocdo - 5;
            if (tocdo > 0)
            {
                cout << "---- TOC DO HIEN TAI: " << tocdo << " km/h" << endl;
                checkR = 2;
                checkD = 4;
            }
            else
            {
                cout << "---- TOC DO HIEN TAI LA 0 km/h" << endl;
                tocdo = 0;
            }

            CanhBao(tocdo);
            ShowMenu_R_D();

        } while (tocdo < 0);

        break;
    case 3:
        system("cls");
        cout << "DUNG XE " << endl;
        tocdo = 0;
        cout << "TOC DO HIEN TAI 0 KM/H " << endl;
        ShowMenu();
        break;
    case 4:
        system("cls");
        ShowMenu();
        break;
    default:
        break;
    }
}

/*================================================================================================*/
/**
* @brief     CanhBao function.
* @details   Canh bao khi qua toc do doi voi che do R hoac D
/*================================================================================================*/
void CanhBao(int tocdo)
{
    if (luachon == 2)
    {
        if (tocdo > TOCDOCANHBAO_R)
        {
            cout << "TOC DO NGUY HIEM, BAN NEN GIAM TOC DO" << endl;
        }
    }

    else if (luachon == 4)
    {
        if (tocdo > TOCDOCANHBAO_D)
        {
            cout << "TOC DO NGUY HIEM, BAN NEN GIAM TOC DO" << endl;
        }
    }

    else
    {
        /* code */
    }
}

void powerOff()
{
     system("cls");
    cout << "POWER OFF" << endl;
    cout << "XE DA O CHE DO TAT MAY" << endl;
    system("pause");
}

/*================================================================================================*/
/**
* @Description  Check whether the string inputs is numberic or not
* @brief     CanhBao function.
* @details   Canh bao khi qua toc do doi voi che do R hoac D
* Result: Return True if it is, otherwise return False
/*================================================================================================*/
inline bool isNumber(std::string sValue)
{
    for (auto& var : sValue)
    {
        if (var < '0' || var > '9')
        {
            return false;
        }
    }
    return true;
}

/*================================================================================================*/
/**
* @brief     Main function.
*/
/*================================================================================================*/

int main()
{
    system("cls");
    login();
    system("pause");
    return 0;
}


 /***********************************/
//#include <iostream>
//#include <string>
//using namespace std;
//
//bool login(string& enterID);
//void menu();
//void stop(int temp);
//void run(int& speed, int temp, int* arr_speed);
//
//bool checkDigit(string number);
//
//void swap(int* xp, int* yp);
//void bubbleSort(int arr[], int n);
//void selectionSort(int arr[], int n);
//
//void enterArrayID(int* arr, int n);
//void printArrayID(int* arr, int n);
//bool checkArrayID(int arr[], int new_array[], int n);
//
//void warningOverSpeed(int speed, int temp);
//void enterArraySpeed(int* arr, int n);
//void setSafeDistance(int* arr_speed);
//void safeStoppingDistance(int speed, int temp, int* arr);
//
//int main()
//{
//	string enterID;
//	string option_s;
//
//	int option = 0;
//	//bien temp de luu gia tri cu cua option
//	int temp = 0;
//	int speed = 0;
//
//	//mang 3 cap toc do
//	int arr_speed[3];
//
//	cout << "Ma so ca nhan: ";
//	cin >> enterID;
//	//Neu mang nhap vao khong trung voi ma so cai san thi dung chuong trinh
//	if (login(enterID) == false)
//	{
//		std::cout << "\nBan nhap sai ma so ca nhan." << std::endl;
//		std::cout << "\nChao tam biet." << std::endl;
//		system("pause");
//		return 0;
//	}
//
//	system("pause");
//	system("cls");
//	//cai dat 3 cap toc do
//	setSafeDistance(arr_speed);
//	system("pause");
//	system("cls");
//	std::cout << "Xin chao: " << enterID << std::endl;
//
//	do
//	{
//		//Nhap chuoi option_s sau do kiem tra co phai kieu so,
//		//Neu dung kieu so thi kiem tra range 1-5
//		do
//		{
//			safeStoppingDistance(speed, temp, arr_speed);
//			warningOverSpeed(speed, temp);
//			menu();
//			cout << "\n\nXin moi nhap tu 1-5" << endl;
//			cin >> option_s;
//			if (checkDigit(option_s) == true)
//			{
//				option = stoi(option_s);
//			}
//			else
//			{
//				option = 0;
//			}
//			system("cls");
//		} while (option < 1 || option > 5);
//
//		//Chon cac che do dieu khien
//		//TH 1-3 la che do dung P/N
//		//TH 2-4 la che do chay lui tien R/D
//		switch (option)
//		{
//		case 1:
//			if (speed == 0)
//			{
//				temp = option;
//				stop(temp);
//			}
//			else
//			{
//				std::cout << "Hay chac chan xe da dung va van toc bang 0 km/h" << std::endl;
//			}
//			break;
//		case 2:
//			if (speed == 0 || temp == 2)
//			{
//				//Toc do mac dinh ban dau la 7km/h
//				speed = 7;
//				temp = option;
//				run(speed, option, arr_speed);
//			}
//			else
//			{
//				std::cout << "Hay chac chan xe da dung va van toc bang 0 km/h" << std::endl;
//			}
//			break;
//		case 3:
//			if (speed == 0)
//			{
//				temp = option;
//				stop(temp);
//			}
//			else
//			{
//				std::cout << "Hay chac chan xe da dung va van toc bang 0 km/h" << std::endl;
//			}
//			break;
//		case 4:
//			if (speed == 0 || temp == 4)
//			{
//				speed = 7;
//				temp = option;
//				run(speed, option, arr_speed);
//			}
//			else
//			{
//				std::cout << "Hay chac chan xe da dung va van toc bang 0 km/h" << std::endl;
//			}
//			break;
//		case 5:
//			std::cout << "\n\nCam on ban da su dung ung dung." << std::endl;
//			break;
//		default:
//			break;
//		}
//	} while (option != 5);
//	return 0;
//}
//
////Dang nhap tai khoan
//bool login(string& enterID)
//{
//	//Chuoi ma so ca nhan duoc cai dat san
//	string ID = "12348765";
//	//mang ma so ca nhan de so sanh voi mang nhap vao
//	int arr_ID[8];
//	int enter_arr[8];
//
//	//nhap chuoi ID
//	while (enterID != "12345678")
//	{
//		system("cls");
//		cout << "Xin moi nhap lai ma so ca nhan: ";
//		cin >> enterID;
//	}
//
//	//chuyen chuoi ID cai san thanh mang kieu int
//	for (int i = 0; i < 8; ++i)
//	{
//		arr_ID[i] = ID[i] - '0';
//	}
//
//	cout << "Nhap ma so ca nhan, mang " << 8 << " so" << endl;
//	enterArrayID(enter_arr, 8);
//	std::cout << "\nMang ma so ca nhan truoc khi sap xep:" << std::endl;
//	printArrayID(arr_ID, 8);
//	std::cout << "\nMang nhap vao truoc khi sap xep:" << std::endl;
//	printArrayID(enter_arr, 8);
//
//	bubbleSort(arr_ID, 8);
//	selectionSort(enter_arr, 8);
//
//	std::cout << "\n--->Mang ma so ca nhan sau khi sap xep:" << std::endl;
//	printArrayID(arr_ID, 8);
//	std::cout << "\n--->Mang nhap vao sau khi sap xep:" << std::endl;
//	printArrayID(enter_arr, 8);
//
//	//Kiem tra 2 mang sau khi sap xep co bang nhau khong
//	return checkArrayID(arr_ID, enter_arr, 8);
//}
//
////Hien thi man hinh chinh
//void menu()
//{
//	std::cout << "\nXin moi lua chon:" << std::endl;
//	std::cout << "1. P" << std::endl;
//	std::cout << "2. R" << std::endl;
//	std::cout << "3. N" << std::endl;
//	std::cout << "4. D" << std::endl;
//	std::cout << "5. Power off" << std::endl;
//}
//
////Chon che do dung P/N
////Dua ra canh bao su dung phanh tay, dua van toc = 0km/h
//void stop(int temp)
//{
//	if (temp == 1)
//	{
//		std::cout << "Da ve so P" << std::endl;
//		std::cout << "\nChu y su dung phanh tay de dam bao an toan" << std::endl;
//	}
//	else if (temp == 3)
//	{
//		std::cout << "Da ve so N" << std::endl;
//		std::cout << "\nChu y su dung phanh tay de dam bao an toan" << std::endl;
//	}
//}
//
////Chon che do chay D/R
////Kiem tra khoang cach an toan va canh bao toc do
////Tang giam toc do moi lan +-5
//void run(int& speed, int temp, int* arr_speed)
//{
//	string option_run_s;
//	int option_run;
//	do
//	{
//		do
//		{
//			safeStoppingDistance(speed, temp, arr_speed);
//			warningOverSpeed(speed, temp);
//			std::cout << "\n\nMoi lua chon:" << std::endl;
//			std::cout << "1. Tang toc" << std::endl;
//			std::cout << "2. Giam toc" << std::endl;
//			std::cout << "3. Phanh" << std::endl;
//			std::cout << "4. Tro ve menu" << std::endl;
//			cout << "\n\nXin moi nhap tu 1-4" << endl;
//
//			cin >> option_run_s;
//			if (checkDigit(option_run_s) == true)
//			{
//				option_run = stoi(option_run_s);
//			}
//			else
//			{
//				option_run = 0;
//			}
//			system("cls");
//		} while (option_run < 1 || option_run > 4);
//
//		switch (option_run)
//		{
//		case 1:
//			speed = speed + 5;
//			//Toc do tang toc ban dau mac dinh la 7km/h
//			if (speed == 5)
//				speed = 7;
//			break;
//		case 2:
//			speed = speed - 5;
//			if (speed == 2 || speed <= 0)
//				speed = 0;
//			break;
//		case 3:
//			speed = 0;
//			break;
//		case 4:
//			break;
//		default:
//			break;
//		}
//	} while (option_run != 4);
//}
//
////Kiem tra chuoi nhap vao la dang so
//bool checkDigit(string number)
//{
//	for (int i = 0; i < number.length(); ++i)
//	{
//		if (isdigit(number[i]) == false)
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
////Ham doi cho
//void swap(int* xp, int* yp)
//{
//	int temp = *xp;
//	*xp = *yp;
//	*yp = temp;
//}
//
////Sap xep mang theo thuat toan noi bot
//void bubbleSort(int arr[], int n)
//{
//	int i, j;
//	bool swapped;
//	for (i = 0; i < n - 1; i++)
//	{
//		swapped = false;
//		for (j = 0; j < n - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				swap(&arr[j], &arr[j + 1]);
//				swapped = true;
//			}
//		}
//		if (swapped == false)
//			break;
//	}
//}
//
////Sap xep mang theo thuat toan lua chon
//void selectionSort(int arr[], int n)
//{
//	int* i, * j, * min_idx;
//	//Duyet mang theo pointer
//	for (i = arr; i < arr + n - 1; i++)
//	{
//		min_idx = i;
//		for (j = i + 1; j < arr + n; j++)
//		{
//			if (*j < *min_idx)
//				min_idx = j;
//		}
//		swap(min_idx, i);
//	}
//}
//
////Ham nhap mang ID
//void enterArrayID(int* arr, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << "array ID[" << i << "] = ";
//		cin >> arr[i];
//	}
//}
//
////Ham in mang ID
//void printArrayID(int* arr, int n)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//
////Ham nhap mang 3 cap toc do
//void enterArraySpeed(int* arr, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << "array Speed[" << i << "] = ";
//		cin >> arr[i];
//	}
//}
//
////Ham so sanh 2 mang ID bang nhau
//bool checkArrayID(int arr_ID[], int new_array[], int n)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		if (arr_ID[i] != new_array[i])
//			return false;
//	}
//	return true;
//}
//
////Nhap mang 3 cap toc do sau do sap xep tang dan
//void setSafeDistance(int* arr_speed)
//{
//	std::cout << "Nhap 3 muc van toc cai dat: " << std::endl;
//	enterArraySpeed(arr_speed, 3);
//	bubbleSort(arr_speed, 3);
//	std::cout << "Cai dat van toc canh bao khoang cach an toan voi 3 muc van toc:" << std::endl;
//	std::cout << "Van toc muc 1: " << arr_speed[0] << " km/h" << std::endl;
//	std::cout << "Van toc muc 2: " << arr_speed[1] << " km/h" << std::endl;
//	std::cout << "Van toc muc 3: " << arr_speed[2] << " km/h" << std::endl;
//}
//
////Thiet lap khoang cach an toan theo 3 cap toc do
//void safeStoppingDistance(int speed, int temp, int* arr_speed)
//{
//	if (temp == 2 || temp == 4)
//	{
//		if (speed < arr_speed[0])
//		{
//			std::cout << "\nBan chu y giu khoang cach toi thieu la 20m" << std::endl;
//		}
//		if (speed >= arr_speed[0] && speed <= arr_speed[1])
//		{
//			std::cout << "\nBan chu y giu khoang cach toi thieu la 55m" << std::endl;
//		}
//		if (speed > arr_speed[1] && speed <= arr_speed[2])
//		{
//			std::cout << "\nBan chu y giu khoang cach toi thieu la 70m" << std::endl;
//		}
//		if (speed > arr_speed[2])
//		{
//			std::cout << "\nBan chu y giu khoang cach toi thieu la 100m" << std::endl;
//		}
//	}
//}
//
////Thiet lap toc do an toan cho che do D/R
//void warningOverSpeed(int speed, int temp)
//{
//	if (temp == 4)
//	{
//		std::cout << "\n----Che do D, toc do hien tai: " << speed << " km/h" << std::endl;
//		if (speed > 60)
//		{
//			std::cout << "\nToc do nguy hiem, ban nen giam toc do" << std::endl;
//		}
//	}
//	else if (temp == 2)
//	{
//		std::cout << "\n----Che do R, toc do hien tai: " << speed << " km/h" << std::endl;
//		if (speed > 20)
//		{
//			std::cout << "\nToc do nguy hiem, ban nen giam toc do" << std::endl;
//		}
//	}
//	else if (temp == 1 || temp == 3)
//	{
//		std::cout << "\n----Toc do hien tai: " << speed << " km/h" << std::endl;
//	}
//}