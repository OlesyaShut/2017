#include "dk_tool.h"
#include <stdlib.h>
#include <string.h>




int addBook( BookShelf *aShelf, char* author, char* title )
{
	int theResult = 0;

	if (NULL != aShelf && NULL != author && NULL != title )
	{
		if (aShelf->current_size < aShelf->aSize)
		{
			book *Da_Vinci_Code = &(aShelf->books[aShelf->current_size]);

			Da_Vinci_Code->title = (char *)malloc(sizeof(char)*(strlen(title)+1));
			strcpy(Da_Vinci_Code->title, title);

			Da_Vinci_Code->author = (char *)malloc(sizeof(char)*(strlen(author)+1));
			strcpy(Da_Vinci_Code->author, author);

			aShelf->current_size ++;
		}
		else
		{
			theResult = -1;
		}
	}
	else
	theResult = -2;

	return theResult;
}

BookShelf *createBookShelf (int aSize)
{
	BookShelf *The_Open_Boat = (BookShelf *) malloc(sizeof(BookShelf));

	if(NULL != The_Open_Boat)
	{
		The_Open_Boat->books = (book *) malloc(sizeof(book) * aSize);
		memset(The_Open_Boat->books, 0, aSize * sizeof(book));

		The_Open_Boat->aSize = aSize;
		The_Open_Boat->current_size = 0;
	}
	return The_Open_Boat;
}

void destroyBookShelf(BookShelf *aShelf)
{
	if (NULL != aShelf)
	{
		if( NULL != aShelf->books )
		{
			int i;
			for(i = 0; i < aShelf->current_size; i++)
			{
				book *aBook = &(aShelf->books[i]);

				if (NULL != aBook->author)
					free(aBook->author);

				if(NULL != aBook->title )
					free(aBook->title);
			}
			free(aShelf->books);
		}
		free(aShelf);
	}

}

void printBookShelf(BookShelf *aShelf)
{
	int i;
	for(i = 0; i < aShelf->current_size; i++)
	{
		printf("Book #%i \n", i );
		book *Da_Vinci_Code = &(aShelf->books[i]);
		printBook(Da_Vinci_Code);
	}
}

void printBook(book *aBook)
{
	printf("Title  = \"%s\" \n", aBook->title );
	printf("Author = \"%s\" \n", aBook->author );
	printf("\n");
}

/*void writeBook(FILE *aFile, book *BookS)
{
	fprintf (aFile, "{");
	writeString(aFile, "Author name", BookS->author);
	fprintf (aFile, ",");
	fprintf (aFile, "\"Title\":\"%s\"", BookS->title);
	fprintf (aFile, "}");
}
void writeBookShelf(FILE *aFile, BookShelf *Shelf)
{
	fprintf (aFile, "{");
	fprintf(aFile, "\"size\":%d", Shelf->aSize);
	fprintf(aFile, ",");
	fprintf(aFile, "\"current_size\":%d", Shelf->current_size);
	fprintf(aFile, ",");
	fprintf(aFile, "\"books\":");
	if (NULL == Shelf->books)
	{
		fprintf(aFile, "null");
	}
	else
	{
		fprintf(aFile, "[");
		int i;
		for ( i=0; i < Shelf->current_size; i++)
		{
			book *aBook = &(Shelf->books[i]);
			writeBook(aFile,aBook);
			if (i < (Shelf->current_size - 1))
			{
				fprintf (aFile, ",");
			}
		}
		fprintf(aFile, "]");
	}
	fprintf (aFile, "}");
}
*/

void bubbleSort(BookShelf *aShelf, int aSize)
{
	int theOut;

	for (theOut; theOut > 1; theOut --)// 1 öèêë
	{
		int theIn = 0;

		for (theIn; theIn < theOut; theIn ++)//2 öèêë
		{
			if (aShelf->books[theIn].title > aShelf->books[theIn+ 1].title )
			{
				book *timeBook = aShelf->books[theIn].title;
				aShelf->books[theIn].title = aShelf->books[theIn + 1].title;
                aShelf->books[theIn + 1].title = timeBook;
			}
		}
	}
}

void selectionSort(BookShelf *aShelf, int aSize)
{
		int i = 0;
	for (i=0; i < aSize - 1; i ++)
	{
		int theMinIndex = i;

		int theIn = i + 1;
		for (theIn; theIn < aSize; theIn ++)
		{
			if (aShelf->books[theIn].title < aShelf->books[theMinIndex].title)
			{
				theMinIndex = theIn;
			}
		}

		book *timeBook = aShelf->books[theIn].title;
		aShelf->books[theIn].title = aShelf->books[theMinIndex].title;
        aShelf->books[theMinIndex].title = timeBook;
	}
}
void insertionSort(BookShelf *aShelf,  int aSize)
{
	int i = 1;
	for (i; i < aSize; i ++)
	{
	    int theIn = i;
		book *timeBook = aShelf->books[theIn].title[i];


		while (theIn > 0 && aShelf->books[theIn - 1].title >= timeBook)
		{
			aShelf->books[theIn].title = aShelf->books[theIn -1 ].title;
			-- theIn;
		}

		aShelf->books[theIn].title = timeBook;
	}
}
