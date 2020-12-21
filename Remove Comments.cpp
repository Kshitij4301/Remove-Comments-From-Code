#include<stdio.h>
#include<stdlib.h>

void check_comment(char);  
void block_comment();   
void single_comment();


FILE *file1, *file2;

int main(void)
{
    char c;
    file1 = fopen ("file1.txt","r") ;   
    file2 = fopen ("file2.txt","w") ;   
    while((c=fgetc(file1))!=EOF)  
        check_comment(c);   

    fclose(file1);
    fclose(file2);

    return 0;
}


void check_comment(char c)
{
    char d;

    if( c == '/')   
    {
        if((d=fgetc(file1))=='*')   
         block_comment();  

        else if( d == '/')   
        {
          single_comment();

        }
        else
        {
        
            fputc(c,file2);
            fputc(d,file2);
        }
    }

    else
        fputc(c,file2);
}


void block_comment()
{

 char d,e;

    while((d=fgetc(file1))!=EOF)   
    {
  
        if(d=='*')  
        {
            e=fgetc(file1); 

            if(e=='/')  
                return;
        }
   }

}


void single_comment()
{
 char d,e;

    while((d=fgetc(file1)))

     {
         if(d=='\n')  
            return;  

    }

}
