#include <windows.h>
#include <excpt.h>
#include <stdio.h>

/* The exception handler */
#ifndef _WIN64
extern "C" EXCEPTION_DISPOSITION _exception_filter(struct _EXCEPTION_RECORD* ed,void *v1,_CONTEXT *cont,void* v2) 
#else
extern "C" long _exception_filter (EXCEPTION_POINTERS *exception_data)
#endif
{ 
#ifdef _WIN64
  struct _EXCEPTION_RECORD* ed = exception_data->ExceptionRecord;
#endif
  char s[512];
  sprintf (s, "0x%x\n", (unsigned int) ed->ExceptionCode);
  MessageBox (NULL, s, "Exception code:", MB_OK);                                 
/// RaiseException()                   
switch(ed->ExceptionCode)
{
                 
case EXCEPTION_ACCESS_VIOLATION:
                          MessageBox(0,"Exception: Access vioalation","Exception",16);
                          break;  
case EXCEPTION_BREAKPOINT:
                          MessageBox(0,"Exception: Breakpoint","Exception",16);  
                          break;  
case EXCEPTION_ARRAY_BOUNDS_EXCEEDED:
                          MessageBox(0,"Exception: Array index out of bounds","Exception",16); 
                          break;
case EXCEPTION_STACK_OVERFLOW:
                          MessageBox(0,"Exception: Stack overflow","Exception",16);
                          break;                          
case EXCEPTION_PRIV_INSTRUCTION:
                          MessageBox(0,"Exception: General Protection Fault","Exception",16); 
                          break;                           
case EXCEPTION_ILLEGAL_INSTRUCTION:
                          MessageBox(0,"Exception: Illegal instruction in program","Exception",16); 
                          break;
case EXCEPTION_INT_OVERFLOW:
                          MessageBox(0,"Exception: Integer overflow","Exception",16);
                          break;
case EXCEPTION_INT_DIVIDE_BY_ZERO:
                          MessageBox(0,"Exception: Integer division by zero","Exception",16);
                          break;
case EXCEPTION_FLT_UNDERFLOW :
                          MessageBox(0,"Exception: Floating point value underflow","Exception",16);
                          break;                          
default:       MessageBox(0,"Unknown exception","Exception",16);                     
}    

                                                                                            
exit(666);   // It's better to use ExitProcess()    
                                                                
}
/* Declare exception registration struct */
EXCEPTION_REGISTRATION *er;


/* This macro initializes SEH */
#ifndef _WIN64
#define init_seh()                              \
{                                               \
    er=new EXCEPTION_REGISTRATION;              \
    er->handler=_exception_filter;              \
    __try1(_exception_filter);                  \
}
#else
#define init_seh()                              \
{                                               \
    __try1(_exception_filter);                  \
}
#endif
/* This stops SEH */
#define stop_seh(void)                          \
{                                               \
__except1;                                      \
}     

int zero = 0;
int val = 100;

int main()
{
init_seh()

/* let's crash our program */
int a=val/zero;
//short *ex=(short*)0xb800000;
//ex[0]='a';



stop_seh();
}
