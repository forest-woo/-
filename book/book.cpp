// book.cpp
// 프로그램 설명 : 도서를 관리하기 위한 프로그램
// 버 전     :  Ver 0.5
// 작 성 자  :  김경배
// 작 성 일  : 2025.09.11
// e-mail    : gbkim@seowon.ac.kr
// 수     정 : 
//             - Ver 0.5 작성(main, book.h), 김경배, 2025.09.11
//             - Ver 0.6  : insertBook(), printBook() 2025.10.22 
//             - Ver 0.7  : 자료구조 변경 및 모든 함수 제작, 최우림, 2026.05.21
// copyright : 본프로그램의 저작권은 작성자에게 있고 작성자의 허락없이 사용 및 배포를 금함
//


#include "book.h"

//  Book lib[100];  전역변수로 선언한 경우

//함수설명 : 도서를 검색하는 함수
//함수인자 설명 : 
//  lib : 도서를 입력하고자 하는 도서배열
int searchBook(Library lib, int bookId)
{
    printf("\n 2. 도서를 검색하는 함수 실행\n");
    if (lib.length == 0)
    {
        printf(" # 검색할 도서가 없습니다. \n\n");
        return -101;
    }

    // 1. 검색할 도서번호를 입력받기
    printf(" * 검색할 도서번호를 입력하세요 : ");
    scanf("%d", &bookId);

    // 2. 검색할 도서의 위치를 검색(index <-- i)
    for (int i = 0; i < lib.length; i++) {
        if (lib.library[i].bookId == bookId) {
            // 검색할 도서를 찾음
            printf(" # 도서번호 : %d 인 도서를 찾았습니다.\n\n", bookId);
            outputBook(lib.library[i]);
            return 1;
        }
    }
    // 검색할 도서를 못찾음
    printf(" # 도서번호 : %d 인 도서가 없습니다.\n\n", bookId);
    return 0;
}

//함수설명 : 도서를 삭제하는 함수
//함수인자 설명 : 
//  lib : 도서를 입력하고자 하는 도서배열
int deleteBook(Library *lib)
{
    int bookId;             // 삭제할 도서번호를 위한 변수
    printf("\n 3. 도서를 삭제하는 함수 실행\n");

    // 1. 삭제할 도서를 입력받기(도서번호)
    printf(" * 삭제할 도서번호를 입력하세요 : ");
    scanf("%d", &bookId);

    // 2. 삭제할 도서의 위치를 검색(index <-- i)
    for (int i = 0; i < lib -> length; i++) {
        if (lib->library[i].bookId == bookId) {
            //  삭제할 도서를 찾음 
            for (int index = i; index < lib -> length-1; index++) {
                lib->library[index] = lib->library[index + 1];
            }
            // 3. 도서개수를 감소(-1)
            lib -> length = lib -> length - 1;
            printf(" # 도서번호 : %d 인 도서가 삭제되었습니다.\n\n", bookId);
            return 1;
        }
    }
    // 삭제할 도서를 못찾음
    printf("# 도서번호 : % d 인 도서가 없습니다.\n\n", bookId);
    return 0;
}
//함수설명 : 도서를 수정하는 함수
//함수인자 설명 : 
//  lib : 도서를 입력하고자 하는 도서배열
int	modifyBook(Library *lib)
{
    int bookId;
    printf("\n 4. 도서를 수정하는 함수 실행\n");
    
    if (lib -> length == 0) 
    {
        printf(" # 수정할 도서가 없습니다. \n\n");
        return -101;
    }
    printf(" * 수정할 도서번호를 입력하세요 : ");
    scanf("%d", &bookId);

    for (int i = 0; i < lib -> length; i++) 
    {
    if(lib->library[i].bookId == bookId) 
    {
        //  수정할 도서를 찾음 
        printf(" # 도서번호 : %d 인 도서를 찾았습니다.\n\n", bookId);
        outputBook(lib->library[i]);
        printf(" # 수정할 도서정보를 입력하세요.\n\n");
        lib->library[i] = inputBook(lib);
        printf(" # 도서번호 : %d 인 도서가 수정되었습니다.\n\n", bookId);
        // 도서 정렬
        Book temp;
        for (int index = 0; index < lib -> length; index++) 
        {
            for (int j = 0; j < lib -> length - 1; j++) {
                if (lib -> library[j].bookId > lib -> library[j + 1].bookId) 
                {
                    temp = lib -> library[j];
                    lib -> library[j] = lib -> library[j + 1];
                    lib -> library[j + 1] = temp;
                }
            }
        }
        return 1;
    }
    }
    // 수정할 도서를 못찾음
    printf(" # 도서번호 : %d 인 도서가 없습니다.\n\n", bookId);
    return 0;
}

//함수설명 : 도서를 파일에 저장하는 함수
//함수인자 설명 : 
//  lib : 도서를 입력하고자 하는 도서배열
int saveBook(Library *lib)
{
    printf("\n 5. 도서를 저장하는 함수 실행\n");
    if(lib -> length == 0)
    {
        printf(" # 저장할 도서가 없습니다. \n\n");
        return -101;
    }

    FILE *fp = fopen("book.txt", "w"); // 파일 열기
    if (fp == NULL) {
        printf(" # 파일을 열 수 없습니다.\n\n");
        return -102;
    }

    fprintf(fp, "%d\n", lib -> length); // 도서개수 저장

    for (int i = 0; i < lib -> length; i++) 
    {
        fprintf(fp, "%d\n", lib -> library[i].bookId);
        fprintf(fp, "%s\n", lib -> library[i].bookTitle.bookHanTitle);
        fprintf(fp, "%s\n", lib -> library[i].bookTitle.bookEngTitle);
        fprintf(fp, "%s\n", lib -> library[i].bookAuthor);
        fprintf(fp, "%s\n", lib -> library[i].bookPublishingCompany);
        fprintf(fp, "%d\n", lib -> library[i].bookPages);
        fprintf(fp, "%d\n", lib -> library[i].bookPublishingYear);
        fprintf(fp, "%d\n", lib -> library[i].bookPrice);
        fprintf(fp, "%d\n", lib -> library[i].bookVersion);
        fprintf(fp, "%s\n", lib -> library[i].bookImage);
        fprintf(fp, "%d\n", lib -> library[i].bookISBN);
    }
    fclose(fp); // 파일 닫기
    printf(" # 도서가 파일에 저장되었습니다.\n\n");
    return 0;
}

//함수설명 : 도서를 파일에서 읽어오는 함수
//함수인자 설명 : 
//  lib : 도서를 입력하고자 하는 도서배열
int	loadBook(Library *lib)
{
    printf("\n 6. 도서를 불러오는 함수 실행\n");

    FILE *fp = fopen("book.txt", "r"); // 파일 열기
    if (fp == NULL)
    {
        printf(" # 파일을 열 수 없습니다.\n\n");
        return -102;
    }
    fscanf(fp, "%d\n", &(lib->length)); // 도서개수 읽기

    for(int i = 0; i < lib -> length; i++)
    {
        fscanf(fp, "%d\n", &(lib->library[i].bookId));
        fscanf(fp, "%s\n", lib->library[i].bookTitle.bookHanTitle);
        fscanf(fp, "%s\n", lib->library[i].bookTitle.bookEngTitle);
        fscanf(fp, "%s\n", lib->library[i].bookAuthor);
        fscanf(fp, "%s\n", lib->library[i].bookPublishingCompany);
        fscanf(fp, "%d\n", &(lib->library[i].bookPages));
        fscanf(fp, "%d\n", &(lib->library[i].bookPublishingYear));
        fscanf(fp, "%d\n", &(lib->library[i].bookPrice));
        fscanf(fp, "%d\n", &(lib->library[i].bookVersion));
        fscanf(fp, "%s\n", lib->library[i].bookImage);
        fscanf(fp, "%d\n", &(lib->library[i].bookISBN));
    }
    fclose(fp);

    printf(" # 도서가 파일에서 읽어왔습니다.\n\n");

    return 0;
}
// 함수설명 : 1권의 책을 상세하게 출력하는 함수
void outputBook(const Book book)
{
    printf(" 1. 도서번호 : %d\n", book.bookId);
    printf(" 2. 도 서 명 : %s\n", book.bookTitle.bookHanTitle);
    printf(" 3. 저 자 명 : %s\n", book.bookAuthor);
    printf(" 4. 출판사 : %s\n", book.bookPublishingCompany);
    printf(" 5. 페이지 : %d\n", book.bookPages);
    printf(" 6. 출판년도 : %d\n", book.bookPublishingYear);
    printf(" 7. 가격 : %d\n", book.bookPrice);
    printf(" 8. 판 : %d\n", book.bookVersion);
    printf(" 9. 도서이미지 : %s\n", book.bookImage);
    printf("10. ISBN : %d\n\n", book.bookISBN);
    return;
}

/*void outputBook(Library *lib)
{   
    for(int i = 0; i< lib->length; i++)
    {
        printf(" 1. 도서번호 : %d\n", lib -> library[i].bookId);
        printf(" 2. 도 서 명 : %s\n", lib -> library[i].bookTitle);
        printf(" 3. 저 자 명 : %s\n", lib -> library[i].bookAuthor);
        printf(" 4. 출판사 : %s\n", lib -> library[i].bookPublishingCompany);
        printf(" 5. 페이지 : %d\n", lib -> library[i].bookPages);
        printf(" 6. 출판년도 : %d\n", lib -> library[i].bookPublishingYear);
        printf(" 7. 가격 : %d\n", lib -> library[i].bookPrice);
        printf(" 8. 판 : %d\n", lib -> library[i].bookVersion);
        printf(" 9. 도서이미지 : %s\n", lib -> library[i].bookImage);
        printf("10. ISBN : %d\n\n", lib -> library[i].bookISBN);
    }
    return;
}
*/
//함수설명 : 도서를 출력하는 함수
//함수인자 설명 : 
//  lib : 도서를 입력하고자 하는 도서배열
int printBook(Library* lib)
{
    printf("\n 7. 도서를 출력하는 함수 실행\n");
    for(int i =0; i< lib -> length; i++)
    {
        outputBook(lib->library[i]);
    }
    printf(" # 총 %d 권의 도서가 출력되었습니다.\n\n", lib->length);
    return 0;
}

// 함수설명 : 책한권의 정보를 입력하는 함수
Book inputBook(Library *lib)
{
    Book    book;           // 책정보를 입력하기 위한 구조체 변수 선언
    int isDuplicate = 0;    // 도서번호 중복검사를 위한 변수
    while (1)
    {
        isDuplicate = 0;
        printf(" 1. 도서번호 :"); scanf("%d", &book.bookId);
        for (int i = 0; i < lib->length; i++) {
            if (lib->library[i].bookId == book.bookId) {
                // 도서번호가 중복됨
                printf(" # 도서번호 : %d 는 이미 존재하는 번호입니다. 다른 번호를 입력하세요.\n\n", book.bookId);
                isDuplicate = 1;
                break;
            }   
        }   
        if(!isDuplicate) //중복 없으면 그냥 탈출
        {
            break;
        }
    }

    printf(" 2. 한글 도 서 명 :"); scanf("%s", book.bookTitle.bookHanTitle);
    printf(" 2. 영문 도 서 명 :"); scanf("%s", book.bookTitle.bookEngTitle);
     // 한글도서명, 영문도서명
    printf(" 3. 저 자 명 :"); scanf("%s", book.bookAuthor);
    printf(" 4. 출판사 :"); scanf("%s", book.bookPublishingCompany);
    printf(" 5. 페이지 :"); scanf("%d", &book.bookPages);
    printf(" 6. 출판년도 :"); scanf("%d", &book.bookPublishingYear);
    printf(" 7. 가격 :"); scanf("%d", &book.bookPrice);
    printf(" 8. 판 :"); scanf("%d", &book.bookVersion);
    printf(" 9. 도서이미지 :"); scanf("%s", book.bookImage);
    printf("10. ISBN :"); scanf("%d", &book.bookISBN);
    
    /*
    int		bookId;	
    Title	bookTitle;							// 도서명(한글, 영문)
    char	bookPublishingCompany[MAX_MID_CHAR];// 출판사(string)
    int		bookPages;							// 페이지(int)
    int		bookPublishingYear;					// 출판년도(int --> date)
    int		bookPrice;							// 가격(int)
    int		bookVersion;						// 판(version)(int)
    char	bookImage[MAX_LONG_CHAR];			// 도서이미지(string ==> "C:\book\bookImage\C언어.jpg")
    int		bookISBN;							// ISBN/ISSN 번호
    */
    return  book;
}


//함수설명 : 도서를 입력하는 함수
//함수인자 설명 : 
//  lib : 도서를 입력하고자 하는 도서배열
//  libmax : 도서배열의 최대 크기
//  length : 도서배열에 저장된 데이터(도서)의 개수
// 
// 리턴값 :  -101 - 배열이 full 인 경우

int libFull(Library* lib)
{
    Book* temp;

    //1. 확장된 배열을 위한 정보 설정
    lib -> libMax = lib -> libMax + lib -> increment;

    //2. 확장된 배열 생성하기(new)
    temp = (Book*)malloc(sizeof(Book) * lib -> libMax);

    //3. 기존의 배열 데이터를 확장된 배열로 이동
    for (int i = 0; i < lib->length; i++)
    {
        temp[i] = lib->library[i];
    }

    //4. 이전 배열을 free
    free(lib->library);

    //5. 새로운 확장된 배열로 배열의 주소 이전
    lib->library = temp;

    /*int i;
    element* temp
    pQ->Qsize += pQ ->increment;
    temp = (element*)malloc(pQ->Qsize * sizeof(element));
    for (i = 0; i < pQ -> legnth; i++)
    {
        temp[i] = pQ->data[i];

    }
    free(pQ->data);
    pQ->data = temp;
    */

    return 0;
}

int insertBook(Library *lib)
{
    if (lib -> libMax <= lib -> length) {   // full
        libFull(lib);
    }

     // 1. 입력할 도서정보 받기   ==> book 구조체 (book.h)
    Book    book;           // 책정보를 입력하기 위한 구조체 변수 선언
    book = inputBook(lib);
    
    // 2. 입력된 도서정보를 배열에 넣기
    lib -> library[lib-> length] = book;
    
    // 3. 도서개수 증가 ==> ㅣength++
    // *length++;
    lib -> length = lib -> length + 1;

    printf(" # 도서번호 : %d 인 도서가 입력되었습니다.\n\n", book.bookId);

    return 0;
}

/*int insertBook(Book lib[], const int max, int *length)
{
    printf("\n 1. 도서를 입력하는 함수 실행\n");

    // 배열에 직접입력하는 기능
    // 0. 도서배열이 full인가(MAX == length)를 검사하기
    if (max <= *length) {   // full
        printf("\n  배열이 full입니다. \n");
        printf("배열의 크기를 증가하세요 !!!\n\n");
        return -101;
    }
    
    // 1. 입력할 도서정보 받기   ==> book 구조체 (book.h)
    Book    book;           // 책정보를 입력하기 위한 구조체 변수 선언
    book = inputBook();

    // 2. 입력된 도서정보를 배열에 넣기
    lib[*length] = book;

    // 3. 도서개수 증가 ==> ㅣength++
    // *length++;
    *length = *length + 1;

    return 0;
}
*/

// 함수설명: 도서관리 메뉴를 출력하고 선택된 번호를 리턴함
int mainMenu()
{
    int choice = 0;

    printf("\n\t\t\t 도서관리 프로그램\n");
    printf("\t\t==================================\n");
    printf("\t\t 1. 도 서 입 력\n");
    printf("\t\t 2. 도 서 검 색\n");
    printf("\t\t 3. 도 서 삭 제\n");
    printf("\t\t 4. 도 서 수 정\n");
    printf("\t\t 5. 도 서 저 장\n");
    printf("\t\t 6. 도 서 불 러 오 기\n");
    printf("\t\t 7. 도 서 출 력\n\n");
    printf("\t\t 0. 프로그램 종료\n\n\n");

    printf("\t\t # 번호를 선택하세요 : ");
    scanf("%d", &choice);

    return  choice;
}
Library createLibrary(int max, int inc)
{
    Library lib;

    lib.length = 0;
    lib.libMax = max;
    lib.increment = inc;
    lib.library = (Book*)malloc(sizeof(Book));

    return lib;
}

int main()
{
    Library library;

    library = createLibrary(MAX_BOOK_SIZE,2);

    int     choice = 0;     // 메뉴 선택을 위한 변수
    
    // 3. 선택된 메뉴 실행(함수호출)
    // 4. 2-3 반복
    do {          // do ~ while(1)
    // 2. 메인 메뉴를 출력하고 원하는 메뉴 선택하기  ==> switch ~ case
        choice = mainMenu();
        switch (choice) {
        case 1:   // 1. 도 서 입 력
            //insertBook(library, max, &length);
            insertBook(&library);
            break;
        case 2:   //  2. 도 서 검 색
            {
            //int tempBookId = 0; // 검색할 도서번호를 입력받기 위한 변수
            //searchBook(library, tempBookId);
            break;
            }
        case 3:   // 3. 도 서 삭 제
            //deleteBook(&library);
            break;
        case 4:   // 4. 도 서 수 정
            //modifyBook(&library);
            break;
        case 5:   // 5. 도 서 저 장
            //saveBook(&library);
            break;
        case 6:   // 6. 도 서 불 러 오 기
            //loadBook(&library);
            break;
        case 7:   // 7. 도 서 출 력
            printBook(&library);
            break;
        case 0:   // 0. 프그램 종료
        default:
            return 0;
            break;

        }
    } while (1);

    free(library.library);
    return 0;
}
