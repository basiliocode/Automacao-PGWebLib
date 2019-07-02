/*********************** SETIS - Automa��o e Sistemas ************************

 Arquivo          : PWL_Type.h
 Projeto          : Pay&Go WEB
 Plataforma       : Win32
 Data de cria��o  : 30/08/2013
 Autor            : Guilherme Eduardo Leite
 Descri��o        : Defini��es dos tipos utiliza na plataforma Windows pela
                    dll para integra��o com a solu��o Pay&Go WEB.
 ================================= HIST�RICO =================================
 Data      Respons�vel Modifica��o
 --------  ----------- -------------------------------------------------------
\*****************************************************************************/

#ifndef _PWLTYPE_INCLUDED_
#define _PWLTYPE_INCLUDED_

// Tipos b�sicos utilizados
#ifndef PW_EXPORT 
#define PW_EXPORT __stdcall
#endif /* PW_EXPORT */

typedef char           Int8;
typedef unsigned char  Uint8;

typedef short          Int16;
typedef unsigned short Uint16;

typedef long           Int32;
typedef unsigned long  Uint32;

typedef unsigned char  Byte;

typedef unsigned short Word;
typedef unsigned long  Dword;

typedef int            Bool;


// Valor m�ximo que pode ser atribu�do a um tipo Int16
#ifndef MAXINT16
#define MAXINT16        32767
#endif /* MAXINT16 */

#endif

