#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start_size, end_size;
   
    // TODO: Prompt for start size
    do
    {
        start_size = get_int("start_size: ");
    }
    
    while (start_size < 9);
     
    // TODO: Prompt for end size

    do
    {
        end_size = get_int("end_size: ");
    }
    
    while (end_size < start_size);
    

    // TODO: Calculate number of years until we reach threshold
   
    int year = 0;    
    
    while (start_size < end_size)  //KONDISI
    {
        int born = start_size / 3;  //STATEMENT YG AKAN DIEKSEKUSI
        int pass_away = start_size / 4;
        start_size = start_size + born - pass_away;
        year++;
    }
    
    // TODO: Print number of years

    printf("Years: %i\n", year);   

}
