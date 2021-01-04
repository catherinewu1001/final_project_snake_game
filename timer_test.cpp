#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t t1 = time(NULL);
    
    printf("自 1970 年 1 月 1 日後經過了 %d 秒....\n", t1);
    if(t1 %2 == 0)
        printf("Y");
    
    return 0;
}