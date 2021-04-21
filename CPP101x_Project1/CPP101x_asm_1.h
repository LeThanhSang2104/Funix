
#include<iostream>
#include <string.h>
using namespace std;
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define MSCN  "12345678"
#define TOCDOMACDINH  7
#define TOCDOCANHBAO_D 60
#define TOCDOCANHBAO_R 20

/*================================================================================================
                                        GLOBAL VARIABLE
=================================================================================================*/

string mscn;
int luachon = 0;
int luachon_R_D;
int tocdo;
int check = 0;
int checkR = 0;
int checkD = 0;


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
void login(void);
void ShowMenu(void);
void ShowMenu_R_D(void);
void Welcome(void);
void ChonHanhTrinh_P(void);
void ChonHanhTrinh_N(void);
void ChonHanhTrinh_D(void);
void ChonHanhTrinh_R(void);
void CanhBao(int tocdo);
inline bool isNumber(std::string sValue);


