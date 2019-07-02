/*********************** SETIS - Automação e Sistemas ************************

 Arquivo          : PWL_Type.h
 Projeto          : Pay&Go WEB
 Plataforma       : Win32
 Data de criação  : 30/08/2013
 Autor            : Guilherme Eduardo Leite
 Descrição        : Definições dos tipos utiliza na plataforma Windows pela
                    dll para integração com a solução Pay&Go WEB.
 ================================= HISTÓRICO =================================
 Data      Responsável Modificação
 --------  ----------- -------------------------------------------------------
\*****************************************************************************/

#ifndef _PWLTYPE_INCLUDED_
#define _PWLTYPE_INCLUDED_

// Tipos básicos utilizados
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


// Valor máximo que pode ser atribuído a um tipo Int16
#ifndef MAXINT16
#define MAXINT16        32767
#endif /* MAXINT16 */

#endif

