#include <stdio.h>
#include <stdlib.h>
#define MAX_BOOKS 100


struct Book{
int id;
char title[50];
char author[50];
int is_borrowed;
int student_id;

};

struct Library{
 struct Book books[MAX_BOOKS];  //kütüphanenin kapasitesi
 int book_count;  //kaç kitap olduðunu güncel olarak


};


 void addBook(struct Library *library,int id,const char *title,const char *author){
 if(library->book_count<MAX_BOOKS){
    if(strlen
       (title)==0 || strlen(author)==0){
        printf("invalid input,please enter a valid title or author!\n");
        return;
       }
       struct Book newBook;
       newBook.id =id;
       strcpy(newBook.title,title);
       strcpy(newBook.author,author);
       newBook.is_borrowed = 0;
       newBook.student_id = -1;//kimse daha almadýðý için

       library->books[library->book_count++] = newBook; //girilen yeni kitabý kütüphane adresinde boþ býrakýlan yere býrak daha sonra kitap sayacýný 1 arttýr
       printf("book added\n");

 }else{
     printf("Library is full,can not add book");

   }
 }

void listAllBooks(struct Library *library){
   if(library->book_count ==0){
    printf("library is empty");
    return;
   }
   printf("All Books:\n");
   printf("%-5s %-20s %-20s %-10s\n","ID","title","author","status");
   printf("------------------------------------------\n");
   for(int i=0;i <library->book_count;i++){
    printf("%-5d %-20s %-20s %-10s\n",library->books[i].id,library->books[i].title,library->books[i].author,
          library->books[i].is_borrowed ? "Borrowed" : "Available");
   }

}

void search(struct Library *library,int id){
    for(int i=0;i<library->book_count;i++){
        if(library->books[i].id == id){
            printf("book found\n");
            printf("ID:%d\n",library->books[i].id);
            printf("title:%s\n",library->books[i].title);
            printf("author:%s\n",library->books[i].author);
            printf("studen_id:%d\n",library->books[i].student_id);
            printf("status:%s \n",library->books[i].is_borrowed ? "Borrowed" : "Available");
            return;

        }


    }
    printf("book not found\n");


}


void borrowBook(struct Library *library,int id,int student_id){
   for(int i=0;i<library->book_count;i++){
        if(library->books[i].id ==id){
            if (library->books[i].is_borrowed){
                printf("book is already borrowed");
            }else{
                library->books[i].is_borrowed =1;
                library->books[i].student_id = student_id;
                printf("book borrowed...\n");
            }
            return;

        }

   }
   printf("book id not found...\n");


}

void returnBook(struct Library *library,int id){
            for(int i=0;i<library->book_count;i++){
                if(library->books[i].id ==id){
                    if(library->books[i].is_borrowed){
                        library->books[i].is_borrowed=0;
                        library->books[i].student_id=-1;
                        printf("book returned\n");

                    }else{
                    printf("book is already in library....\n");
                    }
                    return;
                }
            }
            printf("book id not found...\n");


}




int main()
{
    struct Library library;
    library.book_count=0;
    int student_id, id;
    int choice;
    char title[50],author[50];



   do{
    printf("\nLibrary Management System\n");
    printf("1.Add book\n");
    printf("2.List All Books\n");
    printf("3.Search Book by ID\n");
    printf("4.Rent Book\n");
    printf("5.Return Book\n");
    printf("0.Exit\n");
    printf("enter your choice :");
    scanf("%d",&choice);
    switch(choice){
    case 1:
        printf("ID:");
        scanf("%d",&id);
        printf("Title: ");
        getchar(); //enterden gelecek yenilineý engelliyor scanfden gelen int sonra string alýrsan oluyor
        gets(title);
        printf("Author: ");
        gets(author);
        addBook(&library,id,title,author );  //kopyalama iþlemi olmasýn direkt adresine gitsin
        break;
         case 2:
            listAllBooks(&library);
            break;
         case 3:
            printf("enter book id: ");
            scanf("%d",&id);
            search(&library,id);
            break;
         case 4:
            printf("enter a book ID to borrow: ");
            scanf("%d",&id);
            printf("enter a student_id: ");
            scanf("%d",&student_id);
            borrowBook(&library,id,student_id);
            break;
         case 5:
            printf("enter book ID to return: ");
            scanf("%d",&id);
            returnBook(&library,id);
            break;
         case 0:
            printf("exit.....\n ");

            default:
        if(choice !=0){
        printf("invalid choice.Please try again\n");
}



    }





   }while(choice != 0);






























    return 0;
}
