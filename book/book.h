#pragma once

#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>


#define			MAX_MID_CHAR		50
#define			MAX_LONG_CHAR		100
#define			MAX_BOOK_SIZE		4			


typedef struct Title {
	char	bookHanTitle[MAX_LONG_CHAR];
	char	bookEngTitle[MAX_LONG_CHAR];

} Title;

typedef struct Book
{
	int		bookId;								
	Title	bookTitle;				
	char	bookAuthor[MAX_MID_CHAR];			
	char	bookPublishingCompany[MAX_MID_CHAR];
	int		bookPages;							
	int		bookPublishingYear;					
	int		bookPrice;							
	int		bookVersion;						
	char	bookImage[MAX_LONG_CHAR];			
	int		bookISBN;							
	
} Book;


typedef struct
{
    int length; 
    int libMax; 
    int increment; 
    Book* library;
} Library;


int mainMenu();

// int	insertBook(Book lib[], const int max, int* length);  
int insertBook(Library *lib);

Book inputBook(Library *lib);
int	printBook(Library lib);
void outputBook(const Book book);

int deleteBook(Library *lib);


int searchBook(Library lib, int bookId);
int	modifyBook(Library *lib);
int saveBook(Library *lib);
int	loadBook(Library *lib);

/*

int	insertBoonMenu();
int	insertBookFromKeyboard();
int	insertBookFromTextFile();

int	printBook();
int printBookMenu();
int	printBookToScreen();
int printBookToFile();

int searchBook();
int deleteBook();
int	modifyBook();
int saveBook();
int	loadBook();

*/















