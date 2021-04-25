/*------------------------------------------------------------------------*/
/**
 * @file	NewtPrint.c
 * @brief   プリント関係
 *
 * @author  M.Nukui
 * @date	2005-04-11
 *
 * Copyright (C) 2003-2005 M.Nukui All rights reserved.
 */


/* ヘッダファイル */
#include <ctype.h>

#include "NewtPrint.h"
#include "NewtCore.h"
#include "NewtObj.h"
#include "NewtEnv.h"
#include "NewtIO.h"


/* 関数プロトタイプ */

static int32_t		NewtGetPrintLength(void);
static int32_t		NewtGetPrintDepth(void);
static int32_t		NewtGetPrintIndent(void);
static int32_t      NewtGetPrintBinaries(void);
static int32_t      NewtGetPrintUnique(void);

static bool			NewtSymbolIsPrint(char * str, int len);
static bool			NewtStrIsPrint(char * str, int len);
static char *		NewtCharToEscape(int c);

static void			NIOPrintIndent(newtStream_t * f, int32_t level);
static void			NIOPrintEscapeStr(newtStream_t * f, char * str, int len, char bar);
static void			NIOPrintRef(newtStream_t * f, newtRefArg r);
static void			NIOPrintSpecial(newtStream_t * f, newtRefArg r);
static void			NIOPrintInteger(newtStream_t * f, newtRefArg r);
static void			NIOPrintReal(newtStream_t * f, newtRefArg r);
static void			NIOPrintObjCharacter(newtStream_t * f, newtRefArg r);
static void			NIOPrintObjNamedMP(newtStream_t * f, newtRefArg r);
static void			NIOPrintObjMagicPointer(newtStream_t * f, newtRefArg r);
static void         NIOPrintObjBinaryInstructions(newtStream_t * f, newtRefArg r, newtRefArg codeBlock, int32_t depth);
static void			NIOPrintObjBinary(newtStream_t * f, newtRefArg r, int32_t depth);
static void			NIOPrintObjSymbol(newtStream_t * f, newtRefArg r);
static void			NIOPrintObjString(newtStream_t * f, newtRefArg r);
static void			NIOPrintObjArray(newtStream_t * f, newtRefArg r, int32_t depth, bool literal);
static void			NIOPrintFnFrame(newtStream_t * f, newtRefArg r);
static void			NIOPrintRegexFrame(newtStream_t * f, newtRefArg r);
static void			NIOPrintObjFrame(newtStream_t * f, newtRefArg r, int32_t depth, bool literal);
static void			NIOPrintLiteral(newtStream_t * f, newtRefArg r, bool * literalP);
static void			NIOPrintObj2(newtStream_t * f, newtRefArg r, int32_t depth, bool literal);

static void			NIOPrintCharacter(newtStream_t * f, newtRefArg r);
static void			NIOPrintSymbol(newtStream_t * f, newtRefArg r);
static void			NIOPrintString(newtStream_t * f, newtRefArg r);
static void			NIOPrintArray(newtStream_t * f, newtRefArg r);
static void			NIOPrintObj(newtStream_t * f, newtRefArg r);
static void			NIOPrint(newtStream_t * f, newtRefArg r);

static void			NIOInfo(newtStream_t * f, newtRefArg r);


#if 0
#pragma mark -
#endif
/*------------------------------------------------------------------------*/
/** 配列またはフレームのプリント可能な長さを返す
 *
 * @return			プリント可能な長さ
 */

int32_t NewtGetPrintLength(void)
{
    newtRefVar	n;
    int32_t		printLength = -1;
    
    n = NcGetGlobalVar(NSSYM0(printLength));
    
    if (NewtRefIsInteger(n))
        printLength = (int32_t)NewtRefToInteger(n);
    
    if (printLength < 0)
        printLength = 0x7fffffff;
    
    return printLength;
}


/*------------------------------------------------------------------------*/
/** 配列またはフレームのプリント可能な深さを返す
 *
 * @return			プリント可能な深さ
 */

int32_t NewtGetPrintDepth(void)
{
    newtRefVar	n;
    int32_t		depth = 3;
    
    n = NcGetGlobalVar(NSSYM0(printDepth));
    
    if (NewtRefIsInteger(n))
        depth = (int32_t)NewtRefToInteger(n);
    
    return depth;
}


/*------------------------------------------------------------------------*/
/** Get the number of tabs (or spaces if negative) for indenting.
 *
 * @return			number of characters to indent
 */

int32_t NewtGetPrintIndent(void)
{
    newtRefVar	n;
    int32_t		indent = 1;
    
    n = NcGetGlobalVar(NSSYM0(printIndent));
    
    if (NewtRefIsInteger(n))
        indent = (int32_t)NewtRefToInteger(n);
    
    return indent;
}


/*------------------------------------------------------------------------*/
/** If set, print binary objects as well.
 *
 * @return            0 or 1
 */

int32_t NewtGetPrintBinaries(void)
{
    newtRefVar    n;
    int32_t        pb = 0;

    n = NcGetGlobalVar(NSSYM0(printBinaries));

    if (NewtRefIsInteger(n))
        pb = (int32_t)NewtRefToInteger(n);

    return pb;
}


/*------------------------------------------------------------------------*/
/** If set, print objects only once, even if they are referenced multiple times.
 *
 * @return            0 or 1
 */
int32_t NewtGetPrintUnique(void)
{
    newtRefVar    n;
    int32_t        pu = 0;

    n = NcGetGlobalVar(NSSYM0(printUnique));

    if (NewtRefIsInteger(n))
        pu = (int32_t)NewtRefToInteger(n);

    return pu;
}


#if 0
#pragma mark -
#endif
/*------------------------------------------------------------------------*/
/** シンボル文字列が表示可能か調べる
 *
 * @param str		[in] シンボル文字列
 * @param len		[in] 文字列の長さ
 *
 * @retval			true	表示可能
 * @retval			false	表示不可
 */

bool NewtSymbolIsPrint(char * str, int len)
{
    int c;
    int i;
    
    if (len == 0)
        return false;
    
    c = str[0];
    
    if ('0' <= c && c <= '9')
        return false;
    
    for (i = 0; i < len && str[i]; i++)
    {
        c = str[i];
        
        if (c == '_') continue;
        if ('a' <= c && c <= 'z') continue;
        if ('A' <= c && c <= 'Z') continue;
        if ('0' <= c && c <= '9') continue;
        
        return false;
    }
    
    return true;
}


/*------------------------------------------------------------------------*/
/** 文字列が表示可能か調べる
 *
 * @param str		[in] 文字列
 * @param len		[in] 文字列の長さ
 *
 * @retval			true	表示可能
 * @retval			false	表示不可
 */

bool NewtStrIsPrint(char * str, int len)
{
    int		i;
    
    for (i = 0; i < len && str[i]; i++)
    {
        if (str[i] == '"')
            return false;
        
        if (! isprint((unsigned char)str[i]))
            return false;
    }
    
    return true;
}


/*------------------------------------------------------------------------*/
/** Convert a bunch characters into their escaped variant.
 *  This is required when printing symbols containing vertical bars.
 *
 * @param c			[in] unicode character
 *
 * @return		 	ASCII string or NULL
 */

char * NewtCharAndBarToEscape(int c)
{	
    if (c=='|') {
        return "\\|";
    } else if (c=='\\') { 
        return "\\\\";
    } else {
        return NewtCharToEscape(c);
    }
}


/*------------------------------------------------------------------------*/
/** 文字をエスケープ文字列に変換する
 *
 * @param c			[in] 文字
 *
 * @return			エスケープ文字列
 */

char * NewtCharToEscape(int c)
{
    char *	s = NULL;
    
    switch (c)
    {
        case '\n':
            s = "\\n";
            break;
            
        case '\r':
            s = "\\r";
            break;
            
        case '\t':
            s = "\\t";
            break;
            
        case '"':
            s = "\\\"";
            break;
    }
    
    return s;
}


/*------------------------------------------------------------------------*/
/** Print a NewLine character and some spaces to indent the following text. 
 * @param f			[in] destination stream
 * @param depth		[in] max indent level minus current indent level
 */
void NIOPrintIndent(newtStream_t * f, int32_t depth)
{
    int32_t i, n = newt_env._indentDepth - depth;
    NIOFputc('\n', f);
    if (NEWT_INDENT>0) {
        n *= NEWT_INDENT;
        for (i=0; i<n; i++) {
            NIOFputc('\t', f);
        }
    } else {
        n *= -NEWT_INDENT;
        for (i=0; i<n; i++) {
            NIOFputc(' ', f);
        }
    }
}


/*------------------------------------------------------------------------*/
/** 文字列をエスケープでプリントする
 *
 * @param f		[in] 出力ファイル
 * @param str		[in] 文字列
 * @param len		[in] 文字列の長さ
 * @param bar		[in] set to 1 to also create an escape sequence 
 *			     for the vertical bar character
 *
 * @return			なし
 *
 * @note			newtStream_t を使用
 */

void NIOPrintEscapeStr(newtStream_t * f, char * str, int len, char bar)
{
    bool	unicode = false;
    char *	s;
    int		c;
    int		i;
    
    for (i = 0; i < len; i++)
    {
        c = str[i];
        
        if (bar)
            s = NewtCharAndBarToEscape(c);
        else
            s = NewtCharToEscape(c);
        
        if (s != NULL)
        {
            if (unicode)
            {
                NIOFputs("\\u", f);
                unicode = false;
            }
            
            NIOFputs(s, f);
        }
        else if (isprint(c))
        {
            if (unicode)
            {
                NIOFputs("\\u", f);
                unicode = false;
            }
            
            NIOFputc(c, f);
        }
        else
        {
            if (! unicode)
            {
                NIOFputs("\\u", f);
                unicode = true;
            }
            
            NIOFprintf(f, "%02x%02x", (uint8_t)c, (uint8_t)str[++i]);
        }
    }
}


#if 0
#pragma mark -
#endif
/*------------------------------------------------------------------------*/
/** 出力ファイルにオブジェクト参照を１６進数でプリントする
 *
 * @param f			[in] 出力ファイル
 * @param r			[in] オブジェクト
 *
 * @return			なし
 *
 * @note			newtStream_t を使用
 */

void NIOPrintRef(newtStream_t * f, newtRefArg r)
{
    NIOFprintf(f, "ref%08x", r);
}


/*------------------------------------------------------------------------*/
/** Print special objects to output file
 *
 * @param f			[in] 出力ファイル
 * @param r			[in] オブジェクト
 *
 * @return			なし
 *
 * @note			newtStream_t を使用
 */

void NIOPrintSpecial(newtStream_t * f, newtRefArg r)
{
    uint64_t n;
    
    n = NewtRefToSpecial(r);
//    NIOFprintf(f, "<Special, %08x>", n);
    NIOFprintf(f, "$\\s%04x", (uint16_t)n);
}


/*------------------------------------------------------------------------*/
/** 出力ファイルに整数オブジェクトをプリントする
 *
 * @param f			[in] 出力ファイル
 * @param r			[in] オブジェクト
 *
 * @return			なし
 *
 * @note			newtStream_t を使用
 */

void NIOPrintInteger(newtStream_t * f, newtRefArg r)
{
    int64_t	n;
    
    n = NewtRefToInteger(r);
    NIOFprintf(f, "%lld", n);
}


/*------------------------------------------------------------------------*/
/** 出力ファイルに浮動小数点オブジェクトをプリントする
 *
 * @param f			[in] 出力ファイル
 * @param r			[in] オブジェクト
 *
 * @return			なし
 *
 * @note			newtStream_t を使用
 */

void NIOPrintReal(newtStream_t * f, newtRefArg r)
{
    double	n;
    
    n = NewtRefToReal(r);
    NIOFprintf(f, "%f", n);
}


/*------------------------------------------------------------------------*/
/** 出力ファイルに文字オブジェクトをプリントする
 *
 * @param f			[in] 出力ファイル
 * @param r			[in] オブジェクト
 *
 * @return			なし
 *
 * @note			newtStream_t を使用
 */

void NIOPrintObjCharacter(newtStream_t * f, newtRefArg r)
{
    char *	s;
    int		c;
    
    c = NewtRefToCharacter(r);
    
    NIOFputc('$', f);
    
    s = NewtCharToEscape(c);
    
    if (s != NULL)
        NIOFputs(s, f);
    else if (0xff00 & c)
        NIOFprintf(f, "\\u%04x", c);
    else if (isprint(c))
        NIOFputc(c, f);
    else
        NIOFprintf(f, "\\%02x", c);
}


#ifdef __NAMED_MAGIC_POINTER__

/*------------------------------------------------------------------------*/
/** 出力ファイルに名前付マジックポインタをプリントする
 *
 * @param f			[in] 出力ファイル
 * @param r			[in] オブジェクト
 *
 * @return			なし
 *
 * @note			newtStream_t を使用
 */

void NIOPrintObjNamedMP(newtStream_t * f, newtRefArg r)
{
    newtRefVar	sym;
    
    sym = NewtMPToSymbol(r);
    
    NIOFputc('@', f);
    NIOPrintObjSymbol(f, sym);
}

#endif /* __NAMED_MAGIC_POINTER__ */


/*------------------------------------------------------------------------*/
/** 出力ファイルにマジックポインタをプリントする
 *
 * @param f			[in] 出力ファイル
 * @param r			[in] オブジェクト
 *
 * @return			なし
 *
 * @note			newtStream_t を使用
 */

void NIOPrintObjMagicPointer(newtStream_t * f, newtRefArg r)
{
    int32_t	table;
    int32_t	index;
    
    table = NewtMPToTable(r);
    index = NewtMPToIndex(r);
    
    NIOFprintf(f, "@%d", index);
}


/*------------------------------------------------------------------------*/
/** Print bytecode instructions.
 *
 * @param f            [in] output stream
 * @param r            [in] binary object with NewtonScript bytecode instructions
 */

void NIOPrintObjBinaryInstructions(newtStream_t * f, newtRefArg r, newtRefArg codeBlock, int32_t depth)
{
    newtObjRef array = NewtRefToPointer(r);
    uint32_t len = NewtBinaryLength(r);
    uint8_t *data = NewtRefToBinary(r);
    NIOFputs("MakeBinaryFromBC( [", f);

    if (NEWT_INDENT) NIOPrintIndent(f, depth-1);
    newtRef klass = NewtObjArrayClass(array);
    if (NewtRefIsNIL(klass))
        NIOFputs("binary:", f);
    else
        NIOFprintf(f, "%s:", NewtSymbolGetName(klass));

    newtRef literals = NewtObjGetSlot(NewtRefToPointer(codeBlock), NSSYM0(literals));

    // first, mark all the locations that are jump targets and need a label:
    uint8_t *needsLabel = (uint8_t*)calloc(1, len);
    for (uint32_t pc=0; pc<len; ) {
        uint8_t inst = data[pc];
        uint8_t a = inst>>3, n = 1;
        uint16_t b = 0;
        if ( (inst & 0x07) == 0x07 ) {
            b = (data[pc+1]<<8) | (data[pc+2]);
            n = 3;
        } else {
            b = inst & 0x07;
            n = 1;
        }
        if ((a==11) || (a==12) || (a==13) || (a==23)) {
            needsLabel[b] = 1;
        }
        pc += n;
    }

    for (uint32_t pc=0; pc<len; ) {
        if (needsLabel[pc]) {
            if (NEWT_INDENT) NIOPrintIndent(f, depth-1);
            NIOFprintf(f, "    'label_%d,", pc);
        }
        if (NEWT_INDENT) NIOPrintIndent(f, depth-1);
        uint8_t inst = data[pc];
        uint8_t a = inst>>3, n = 1;
        uint16_t b = 0;
        NIOFprintf(f, "/* %3d: ", pc);
        if ( (inst & 0x07) == 0x07 ) {
            // 3 byte instruction
            NIOFprintf(f, "%02X ", inst);
            NIOFprintf(f, "%04X */ ", (data[pc+1]<<8) | (data[pc+2]));
            b = (data[pc+1]<<8) | (data[pc+2]);
            n = 3;
        } else {
            // 1 byte instruction
            NIOFprintf(f, "%02X      */ ", inst);
            b = inst & 0x07;
            n = 1;
        }
        int pLit = 0;
        int pImm = 0;
        switch (a) {
            case 0:
                switch (b) {
                    case 0: NIOFputs("bc:Pop()", f); break;
                    case 1: NIOFputs("bc:Dup()", f); break;
                    case 2: NIOFputs("bc:Ret()", f); break;
                    case 3: NIOFputs("bc:PushSelf()", f); break;
                    case 4: NIOFputs("bc:SetLexScope()", f); break;
                    case 5: NIOFputs("bc:IterNext()", f); break;
                    case 6: NIOFputs("bc:IterDone()", f); break;
                    case 7: NIOFputs("bc:PopHandlers()", f); break;
                    default: NIOFputs("bc:Invalid()", f); break;
                }
                break;
            case 3: NIOFprintf(f, "bc:Push(%d)", b); pLit = 1; break;
            case 4: NIOFprintf(f, "bc:PushConst(%d)", b); pImm = 1; break;
            case 5: NIOFprintf(f, "bc:CallGlobal(%d)", b); break;
            case 6: NIOFprintf(f, "bc:Invoke(%d)", b); break;
            case 7: NIOFprintf(f, "bc:Send(%d)", b); break;
            case 8: NIOFprintf(f, "bc:SendIfDef(%d)", b); break;
            case 9: NIOFprintf(f, "bc:Resend(%d)", b); break;
            case 10: NIOFprintf(f, "bc:ResendIfDef(%d)", b); break;
            case 11: NIOFprintf(f, "bc:Branch('label_%d)", b); break;
            case 12: NIOFprintf(f, "bc:BranchIfTrue('label_%d)", b); break;
            case 13: NIOFprintf(f, "bc:BranchIfFalse('label_%d)", b); break;
            case 14: NIOFprintf(f, "bc:FindVar(%d)", b); pLit = 1; break;
            case 15: NIOFprintf(f, "bc:GetVar(%d)", b); break;
            case 16: NIOFprintf(f, "bc:MakeFrame(%d)", b); break;
            case 17: NIOFprintf(f, "bc:MakeArray(%d)", b); break;
            case 18: NIOFprintf(f, "bc:GetPath(%d)", b); break;
            case 19: NIOFprintf(f, "bc:SetPath(%d)", b); break;
            case 20: NIOFprintf(f, "bc:SetVar(%d)", b); break;
            case 21: NIOFprintf(f, "bc:FindAndSetVar(%d)", b); pLit = 1; break;
            case 22: NIOFprintf(f, "bc:IncrVar(%d)", b); break;
            case 23: NIOFprintf(f, "bc:BranchIfNotDone('label_%d)", b); break;
            case 24:
                switch (b) {
                    case 0: NIOFputs("bc:Add()", f); break;
                    case 1: NIOFputs("bc:Subtract()", f); break;
                    case 2: NIOFputs("bc:ARef()", f); break;
                    case 3: NIOFputs("bc:SetARef()", f); break;
                    case 4: NIOFputs("bc:Equals()", f); break;
                    case 5: NIOFputs("bc:LNot()", f); break;
                    case 6: NIOFputs("bc:NotEquals()", f); break;
                    case 7: NIOFputs("bc:Multiply()", f); break;
                    case 8: NIOFputs("bc:Divide()", f); break;
                    case 9: NIOFputs("bc:DivInt()", f); break;
                    case 10: NIOFputs("bc:Less()", f); break;
                    case 11: NIOFputs("bc:Greater()", f); break;
                    case 12: NIOFputs("bc:GreaterOrEqual()", f); break;
                    case 13: NIOFputs("bc:LessOrEqual()", f); break;
                    case 14: NIOFputs("bc:BAnd()", f); break;
                    case 15: NIOFputs("bc:BOr()", f); break;
                    case 16: NIOFputs("bc:BNot()", f); break;
                    case 17: NIOFputs("bc:NewIter()", f); break;
                    case 18: NIOFputs("bc:Length()", f); break;
                    case 19: NIOFputs("bc:Clone()", f); break;
                    case 20: NIOFputs("bc:SetClass()", f); break;
                    case 21: NIOFputs("bc:AddSlot()", f); break;
                    case 22: NIOFputs("bc:Stringer()", f); break;
                    case 23: NIOFputs("bc:HasPath()", f); break;
                    case 24: NIOFputs("bc:ClassOf()", f); break;
                    default: NIOFputs("bc:Invalid()", f); break;
                }
                break;
            case 25: NIOFprintf(f, "bc:NewHandlers(%d)", b); break;
            default: NIOFputs("bc:Invalid()", f); break;
        }
        if (pc<len-1) NIOFputs(",", f); else NIOFputs(" ", f);
        if (pLit==1 && NewtRefIsNotNIL(literals)) {
            NIOFputs(" // ", f);
            newtRef lit = NewtGetArraySlot(literals, b);
            if (NewtRefIsArray(lit)) NIOFputs("[ ... ]", f);
            else if (NewtRefIsFrame(lit)) NIOFputs("{ ... }", f);
            else NIOPrintObj2(f, NewtGetArraySlot(literals, b), 0, true);
        }
        if (pImm==1) {
            NIOFputs(" // ", f);
            newtRef imm = (newtRef)((int32_t)((int16_t)(b)));
            NIOPrintObj2(f, imm, 0, true);
        }
        pc += n;
    }
    if (NEWT_INDENT) NIOPrintIndent(f, depth);
    NIOFputs("] )", f);

    free(needsLabel);
}


/*------------------------------------------------------------------------*/
/** 出力ファイルにバイナリオブジェクトをプリントする
 *
 * @param f			[in] 出力ファイル
 * @param r			[in] オブジェクト
 *
 * @return			なし
 *
 * @note			newtStream_t を使用
 */

void NIOPrintObjBinary(newtStream_t * f, newtRefArg r, int32_t depth)
{
    newtRefVar	klass;
    int	len;
    
    len = NewtBinaryLength(r);
    klass = NcClassOf(r);
    if (newt_env._printBinaries)
    {
        uint8_t *data = NewtRefToBinary(r);
        NIOFputs("MakeBinaryFromHex(", f);
        if (len<=40) {
            NIOFputs("\"", f);
            int i; for (i=0; i<len; i++) NIOFprintf(f, "%02X", data[i]);
            NIOFputs("\", ", f);
        } else {
            int j, i;
            for (j=0; j<len; j+=40) {
                if (NEWT_INDENT) NIOPrintIndent(f, depth-1);
                NIOFputs("\"", f);
                int n = j+40; if (n>len) n = len;
                for (i=j; i<n; i++) NIOFprintf(f, "%02X", data[i]);
                NIOFputs("\"", f);
            }
            NIOFputs(",", f);
            if (NEWT_INDENT) NIOPrintIndent(f, depth-1);
        }
        if (NewtRefIsSymbol(klass))
        {
            NIOFputs("'", f);
            NIOPrintObj2(f, klass, 0, true);
        } else {
            NIOFputs("NIL)", f);
        }
        NIOFputs(")", f);
    } else {
        NIOFputs("<Binary, ", f);
        if (NewtRefIsSymbol(klass))
        {
            NIOFputs("class \"", f);
            NIOPrintObj2(f, klass, 0, true);
            NIOFputs("\", ", f);
        }
        NIOFprintf(f, "length %d>", len);
    }
}


/*------------------------------------------------------------------------*/
/** 出力ファイルにシンボルオブジェクトをプリントする
 *
 * @param f			[in] 出力ファイル
 * @param r			[in] オブジェクト
 *
 * @return			なし
 *
 * @note			newtStream_t を使用
 */

void NIOPrintObjSymbol(newtStream_t * f, newtRefArg r)
{
    newtSymDataRef	sym;
    int		len;
    
    sym = NewtRefToSymbol(r);
    len = NewtSymbolLength(r);
    
    if (NewtSymbolIsPrint(sym->name, len))
    {
        NIOFputs(sym->name, f);
    }
    else
    {
        NIOFputc('|', f);
        NIOPrintEscapeStr(f, sym->name, len, 1);
        NIOFputc('|', f);
    }
}


/*------------------------------------------------------------------------*/
/** 出力ファイルに文字列オブジェクトをプリントする
 *
 * @param f			[in] 出力ファイル
 * @param r			[in] オブジェクト
 *
 * @return			なし
 *
 * @note			newtStream_t を使用
 */

void NIOPrintObjString(newtStream_t * f, newtRefArg r)
{
    char *	s;
    int		len;
    
    s = NewtRefToString(r);
    len = NewtStringLength(r);
    
    if (NewtStrIsPrint(s, len))
    {
        //		NIOFprintf(f, "\"%s\"", s);
        NIOFputs("\"", f);
        NIOFputs(s, f);
        NIOFputs("\"", f);
    }
    else
    {
        NIOFputc('"', f);
        NIOPrintEscapeStr(f, s, len, 0);
        NIOFputc('"', f);
    }
}


/*------------------------------------------------------------------------*/
/** Print the array object to the output file
 *
 * @param f[in] Output file
 * @param r[in] object
 * @param depth[in] depth
 * @param literal[in] Literal flag
 *
 * without @return
 *
 * @note newtStream_t
 */
void NIOPrintObjArray(newtStream_t * f, newtRefArg r, int32_t depth, bool literal)
{
    newtObjRef	obj;
    newtRef *	slots;
    newtRefVar	klass;
    uint32_t	len;
    uint32_t	i;
    
    obj = NewtRefToPointer(r);
    len = NewtObjSlotsLength(obj);
    slots = NewtObjToSlots(obj);
    
    if (newt_env._printUnique) {
        newtObjRef v = NewtRefToPointer(r);
        if (v->header.flags & kNewtObjPrintRefMulti) {
            if (v->header.flags & kNewtObjPrinted) {
                //if (NEWT_INDENT) NIOPrintIndent(f, depth);
                NIOPrintRef(f, r);
                return;
            } else {
                v->header.flags |= kNewtObjPrinted;
                //if (NEWT_INDENT) NIOPrintIndent(f, depth);
                NIOPrintRef(f, r);
                NIOFputs(" := ", f);
            }
        }
    }

    if (literal && NcClassOf(r) == NSSYM0(pathExpr))
    {
        for (i = 0; i < len; i++)
        {
            if (0 < i)
                NIOFputs(".", f);
            
            NIOPrintObj2(f, slots[i], 0, literal);
        }
    }
    else
    {
        NIOFputs("[", f);
        
        klass = NcClassOf(r);
        
        if (NewtRefIsNotNIL(klass) && ! NewtRefEqual(klass, NSSYM0(array)))
        {
            if (NEWT_INDENT) NIOPrintIndent(f, depth-1);
            NIOPrintObj2(f, klass, 0, true);
            NIOFputs(": ", f);
        }
        
        if (depth < 0)
        {
            NIOPrintRef(f, r);
        }
        else
        {
            int32_t	printLength;
            
            depth--;
            printLength = NewtGetPrintLength();
            
            for (i = 0; i < len; i++)
            {
                if (0 < i)
                    NIOFputs(", ", f);
                
                if (printLength <= i)
                {
                    NIOFputs("...", f);
                    break;
                }
                
                if (NEWT_INDENT) NIOPrintIndent(f, depth);
                NIOPrintObj2(f, slots[i], depth, literal);
            }
            depth++;
        }
        
        if (NEWT_INDENT) NIOPrintIndent(f, depth);
        NIOFputs("]", f);
    }
}


/*------------------------------------------------------------------------*/
/** 出力ファイルに関数オブジェクトをプリントする
 *
 * @param f			[in] 出力ファイル
 * @param r			[in] オブジェクト
 *
 * @return			なし
 *
 * @note			newtStream_t を使用
 */

void NIOPrintFnFrame(newtStream_t * f, newtRefArg r)
{
    newtRefVar	indefinite;
    int32_t		numArgs;
    char *		indefiniteStr = "";
    
    numArgs = (int32_t)NewtRefToInteger(NcGetSlot(r, NSSYM0(numArgs)));
    indefinite = NcGetSlot(r, NSSYM0(indefinite));
    
    if (NewtRefIsNotNIL(indefinite))
        indefiniteStr = "...";
    
    NIOFprintf(f, "<function, %d arg(s)%s #%08x>", numArgs, indefiniteStr, r);
}


/*------------------------------------------------------------------------*/
/** 出力ファイルに正規表現オブジェクトをプリントする
 *
 * @param f			[in] 出力ファイル
 * @param r			[in] オブジェクト
 *
 * @return			なし
 *
 * @note			newtStream_t を使用
 */

void NIOPrintRegexFrame(newtStream_t * f, newtRefArg r)
{
    newtRefVar	pattern;
    newtRefVar	option;
    
    pattern = NcGetSlot(r, NSSYM0(pattern));
    option = NcGetSlot(r, NSSYM0(option));
    
    //    NIOFprintf(f, "/%s/", NewtRefToString(pattern));
    NIOFputs("/", f);
    NIOFputs(NewtRefToString(pattern), f);
    NIOFputs("/", f);
    
    if (NewtRefIsString(option))
        NIOFputs(NewtRefToString(option), f);
}


/*------------------------------------------------------------------------*/
/** 出力ファイルにフレームオブジェクトをプリントする
 *
 * @param f			[in] 出力ファイル
 * @param r			[in] オブジェクト
 * @param depth		[in] 深さ
 * @param literal	[in] リテラルフラグ
 *
 * @return			なし
 *
 * @note			newtStream_t を使用
 */

void NIOPrintObjFrame(newtStream_t * f, newtRefArg r, int32_t depth, bool literal)
{
    newtObjRef	obj;
    newtRef *	slots;
    newtRefVar	slot;
    uint32_t	index;
    uint32_t	len;
    uint32_t	i;

    if (newt_env._printUnique) {
        newtObjRef v = NewtRefToPointer(r);
        if (v->header.flags & kNewtObjPrintRefMulti) {
            if (v->header.flags & kNewtObjPrinted) {
                NIOPrintRef(f, r);
                return;
            } else {
                v->header.flags |= kNewtObjPrinted;
                NIOPrintRef(f, r);
                NIOFputs(" := ", f);
            }
        }
    }

    if (!newt_env._printBinaries)
    {
        if (NewtRefIsFunction(r) && ! NEWT_DUMPBC)
        {
            NIOPrintFnFrame(f, r);
            return;
        }
        
        if (NewtRefIsRegex(r) && ! NEWT_DUMPBC)
        {
            NIOPrintRegexFrame(f, r);
            return;
        }
    }
    
    obj = NewtRefToPointer(r);
    len = NewtObjSlotsLength(obj);
    slots = NewtObjToSlots(obj);
    
    NIOFputs("{", f);
    
    if (depth < 0)
    {
        NIOPrintRef(f, r);
    }
    else
    {
        bool isFunction = NewtRefIsFunction(r);
        int32_t	printLength;
        
        depth--;
        printLength = NewtGetPrintLength();
        
        for (i = 0; i < len; i++)
        {
            if (0 < i) {
                NIOFputs(", ", f);
            }
            
            if (printLength <= i)
            {
                NIOFputs("...", f);
                if (NEWT_INDENT) NIOPrintIndent(f, depth);
                break;
            }
            if (NEWT_INDENT) NIOPrintIndent(f, depth);
            
            slot = NewtGetMapIndex(obj->as.map, i, &index);
            if (slot == kNewtRefUnbind) break;
            
            NIOPrintObjSymbol(f, slot);
            NIOFputs(": ", f);
            if (isFunction && NewtSymbolEqual(slot, NSSYM0(instructions)))
                NIOPrintObjBinaryInstructions(f, slots[i], r, depth);
            else
                NIOPrintObj2(f, slots[i], depth, literal);
            
        }
        if (NEWT_INDENT) NIOPrintIndent(f, depth+1);
    }
    
    NIOFputs("}", f);
}


/*------------------------------------------------------------------------*/
/** 出力ファイルにリテラルの印をプリントする
 *
 * @param f			[in] 出力ファイル
 * @param r			[in] オブジェクト
 * @param literalP	[i/o]リテラルフラグ
 *
 * @return			なし
 *
 * @note			newtStream_t を使用
 */

void NIOPrintLiteral(newtStream_t * f, newtRefArg r, bool * literalP)
{
    if (! *literalP && NewtRefIsLiteral(r))
    {
        NIOFputc('\'', f);
        *literalP = true;
    }
}


/*------------------------------------------------------------------------*/
/** 出力ファイルにオブジェクトをプリント（再帰呼出し用）
 *
 * @param f			[in] 出力ファイル
 * @param r			[in] オブジェクト
 * @param depth		[in] 深さ
 * @param literal	[in] リテラルフラグ
 *
 * @return			なし
 *
 * @note			newtStream_t を使用
 */

void NIOPrintObj2(newtStream_t * f, newtRefArg r, int32_t depth, bool literal)
{
    switch (NewtGetRefType(r, true))
    {
        case kNewtNil:
            NIOFputs("NIL", f);
            break;
            
        case kNewtTrue:
            NIOFputs("TRUE", f);
            break;
            
        case kNewtUnbind:
            NIOFputs("#UNBIND", f);
            break;
            
        case kNewtSpecial:
            NIOPrintSpecial(f, r);
            break;
            
        case kNewtInt62:
        case kNewtInt64:
            NIOPrintInteger(f, r);
            break;
            
        case kNewtReal:
            NIOPrintReal(f, r);
            break;
            
        case kNewtCharacter:
            NIOPrintObjCharacter(f, r);
            break;
            
        case kNewtMagicPointer:
            if (0 <= depth)
            {
                newtRefVar	r2;
                
                r2 = NcResolveMagicPointer(r);
                
                if (! NewtRefIsMagicPointer(r2))
                {
                    NIOPrintObj2(f, r2, depth, literal);
                    break;
                }
            }
            
#ifdef __NAMED_MAGIC_POINTER__
            if (NewtRefIsNamedMP(r))
            {	// Named Magic Ponter
                NIOPrintObjNamedMP(f, r);
                break;
            }
#endif /* __NAMED_MAGIC_POINTER__ */
            
            NIOPrintObjMagicPointer(f, r);
            break;
            
        case kNewtBinary:
            NIOPrintObjBinary(f, r, depth);
            break;
            
        case kNewtArray:
            NIOPrintLiteral(f, r, &literal);
            NIOPrintObjArray(f, r, depth, literal);
            break;
            
        case kNewtFrame:
            NIOPrintLiteral(f, r, &literal);
            NIOPrintObjFrame(f, r, depth, literal);
            break;
            
        case kNewtSymbol:
            NIOPrintLiteral(f, r, &literal);
            NIOPrintObjSymbol(f, r);
            break;
            
        case kNewtString:
            NIOPrintObjString(f, r);
            break;
            
        default:
            NIOFputs("###UNKNOWN###", f);
            break;
    }
}

/**
 * Recursion pert of clearing all printing related flags.
 */
static void ClearFlags(newtRefArg r, int *nCleared, uint32_t pattern)
{
    newtObjRef v = NULL;
    uint32_t type = NewtGetRefType(r, true);
    switch (type)
    {
        case kNewtInt64:    // binary
        case kNewtReal:     // binary
        case kNewtString:   // binary
        case kNewtBinary:
            v = NewtRefToPointer(r);
            if ((v->header.flags & kNewtObjPrintFlags) == pattern)
                return;
            v->header.flags = (v->header.flags & ~kNewtObjPrintFlags) | pattern;
            (*nCleared)++;
            ClearFlags( NewtObjBinaryClass(v), nCleared, pattern );
            break;
        case kNewtFrame:
        case kNewtArray:
            v = NewtRefToPointer(r);
            if ((v->header.flags & kNewtObjPrintFlags) == pattern)
                return;
            v->header.flags = (v->header.flags & ~kNewtObjPrintFlags) | pattern;
            (*nCleared)++;
            // no need to follow class or map
            newtRef *slot = NewtObjToSlots(v);
            int n = NewtObjSlotsLength(v);
            for (uint32_t i=0; i<n; i++)
                ClearFlags( slot[i], nCleared, pattern );
            break;
    }
}

/**
 * Recursively clear all printing related flags in all referenced objects.
 *
 * This function detects nested cyclic recursion and will not get stuck in a loop.
 */
void NIOPrintClearFlags(newtRefArg r)
{
    // loop until setting and clearing the flags changes the same number of
    // objects, which indicates that we have reached the end of recursion
    // without visiting objects twice or following a cyclic recursion.
    for (;;) {
        int n1 = 0;
        ClearFlags(r, &n1, kNewtObjPrintRefOnce);
        int n2 = 0;
        ClearFlags(r, &n2, 0);
        if (n1==n2)
            break;
    }
}

/**
 * Recursively update all printing related flags in all referenced objects.
 *
 * Find all objects that are referenced more than once, so we can print them seperately.
 * Find and mark all objects that are a view, so we can print those seperately as well.
 */
void NIOPrintUpdateFlags(newtRefArg r)
{
    newtObjRef v = NULL;
    uint32_t type = NewtGetRefType(r, true);
    switch (type)
    {
        case kNewtInt64:    // binary
        case kNewtReal:     // binary
        case kNewtString:   // binary
        case kNewtBinary:
            v = NewtRefToPointer(r);
            if (v->header.flags & kNewtObjPrintRefOnce) {
                v->header.flags |= kNewtObjPrintRefMulti;
            } else {
                v->header.flags |= kNewtObjPrintRefOnce;
                NIOPrintUpdateFlags( NewtObjBinaryClass(v) );
            }
            break;
        case kNewtFrame:
        case kNewtArray:
            v = NewtRefToPointer(r);
            if (v->header.flags & kNewtObjPrintRefOnce) {
                v->header.flags |= kNewtObjPrintRefMulti;
            } else {
                v->header.flags |= kNewtObjPrintRefOnce;
                NIOPrintUpdateFlags( NewtObjBinaryClass(v) );
                newtRef *slot = NewtObjToSlots(v);
                int n = NewtObjSlotsLength(v);
                for (uint32_t i=0; i<n; i++)
                    NIOPrintUpdateFlags( slot[i] );
            }
            break;
    }
}


/*------------------------------------------------------------------------*/
/** 出力ファイルにオブジェクトをプリント
 *
 * @param f			[in] 出力ファイル
 * @param r			[in] オブジェクト
 *
 * @return			なし
 *
 * @note			newtStream_t を使用
 */

void NIOPrintObj(newtStream_t * f, newtRefArg r)
{
    int32_t depth = NewtGetPrintDepth();
    newt_env._indentDepth = depth;
    int32_t indent = NewtGetPrintIndent();
    newt_env._indent = indent;
    int32_t pb = NewtGetPrintBinaries();
    newt_env._printBinaries = pb;
    int32_t pu = NewtGetPrintUnique();
    newt_env._printUnique = pu;
    if (newt_env._printUnique) NIOPrintClearFlags(r);
    if (newt_env._printUnique) NIOPrintUpdateFlags(r);
    NIOPrintObj2(f, r, depth, false);
}


/*------------------------------------------------------------------------*/
/** 出力ファイルにオブジェクトをプリント
 *
 * @param f			[in] 出力ファイル
 * @param r			[in] オブジェクト
 *
 * @return			なし
 */

void NewtPrintObj(FILE * f, newtRefArg r)
{
    newtStream_t	stream;
    
    NIOSetFile(&stream, f);
    NIOPrintObj(&stream, r);
}


/*------------------------------------------------------------------------*/
/** 出力ファイルにオブジェクトをプリント（改行あり）
 *
 * @param f			[in] 出力ファイル
 * @param r			[in] オブジェクト
 *
 * @return			なし
 */

void NewtPrintObject(FILE * f, newtRefArg r)
{
    newtStream_t	stream;
    
    NIOSetFile(&stream, f);
    
    NIOPrintObj(&stream, r);
    NIOFputs("\n", &stream);
}


/*------------------------------------------------------------------------*/
/** 出力ファイルに文字オブジェクトをプリントする
 *
 * @param f			[in] 出力ファイル
 * @param r			[in] オブジェクト
 *
 * @return			なし
 *
 * @note			newtStream_t を使用
 */

void NIOPrintCharacter(newtStream_t * f, newtRefArg r)
{
    NIOFputc(NewtRefToCharacter(r), f);
}


/*------------------------------------------------------------------------*/
/** 出力ファイルにシンボルオブジェクトをプリントする
 *
 * @param f			[in] 出力ファイル
 * @param r			[in] オブジェクト
 *
 * @return			なし
 *
 * @note			newtStream_t を使用
 */

void NIOPrintSymbol(newtStream_t * f, newtRefArg r)
{
    newtSymDataRef	sym;
    
    sym = NewtRefToSymbol(r);
    NIOFputs(sym->name, f);
}


/*------------------------------------------------------------------------*/
/** 出力ファイルに文字列オブジェクトをプリントする
 *
 * @param f			[in] 出力ファイル
 * @param r			[in] オブジェクト
 *
 * @return			なし
 *
 * @note			newtStream_t を使用
 */

void NIOPrintString(newtStream_t * f, newtRefArg r)
{
    NIOFputs(NewtRefToString(r), f);
}


/*------------------------------------------------------------------------*/
/** 出力ファイルに配列オブジェクトをプリントする
 *
 * @param f			[in] 出力ファイル
 * @param r			[in] オブジェクト
 *
 * @return			なし
 *
 * @note			newtStream_t を使用
 */

void NIOPrintArray(newtStream_t * f, newtRefArg r)
{
    newtRef *	slots;
    uint32_t	len;
    uint32_t	i;
    
    slots = NewtRefToSlots(r);
    len = NewtLength(r);
    
    for (i = 0; i < len; i++)
    {
        NIOPrint(f, slots[i]);
    }
}


/*------------------------------------------------------------------------*/
/** Print object to output file
 *
 * @param f			[in] 出力ファイル
 * @param r			[in] オブジェクト
 *
 * @return			なし
 *
 * @note			newtStream_t を使用
 */

void NIOPrint(newtStream_t * f, newtRefArg r)
{
    switch (NewtGetRefType(r, true))
    {
        case kNewtNil:
        case kNewtTrue:
        case kNewtUnbind:
            break;
            
        case kNewtSpecial:
            NIOPrintSpecial(f, r);
            break;
            
        case kNewtInt62:
        case kNewtInt64:
            NIOPrintInteger(f, r);
            break;
            
        case kNewtReal:
            NIOPrintReal(f, r);
            break;
            
        case kNewtCharacter:
            NIOPrintCharacter(f, r);
            break;
            
        case kNewtMagicPointer:
        {
            newtRefVar	r2;
            
            r2 = NcResolveMagicPointer(r);
            
            if (! NewtRefIsMagicPointer(r2))
            {
                NIOPrint(f, r2);
            }
        }
            break;
            
        case kNewtArray:
            NIOPrintArray(f, r);
            break;
            
        case kNewtBinary:
        case kNewtFrame:
            break;
            
        case kNewtSymbol:
            NIOPrintSymbol(f, r);
            break;
            
        case kNewtString:
            NIOPrintString(f, r);
            break;
            
        default:
            break;
    }
}


/*------------------------------------------------------------------------*/
/** 出力ファイルにオブジェクトをプリント
 *
 * @param f			[in] 出力ファイル
 * @param r			[in] オブジェクト
 *
 * @return			なし
 */

void NewtPrint(FILE * f, newtRefArg r)
{
    newtStream_t	stream;
    
    NIOSetFile(&stream, f);
    NIOPrint(&stream, r);
}


/*------------------------------------------------------------------------*/
/** 標準出力に関数情報を表示
 *
 * @param r			[in] オブジェクト
 *
 * @return			なし
 *
 * @note			newtStream_t を使用
 */

void NIOInfo(newtStream_t * f, newtRefArg r)
{
    newtRefVar	fn = kNewtRefUnbind;
    
    if (NewtRefIsSymbol(r))
        fn = NcGetGlobalFn(r);
    else
        fn = (newtRef)r;
    
    if (NewtRefIsFunction(fn))
    {
        newtRefVar	docString;
        
        docString = NcGetSlot(fn, NSSYM0(docString));
        
        if (NewtRefIsNotNIL(docString))
        {
            if (NewtRefIsString(docString))
            {
                //                NIOFprintf(f, "%s\n", NewtRefToString(docString));
                NIOFputs(NewtRefToString(docString), f);
                NIOFputs("\n", f);
            }
            else
            {
                NIOPrintObj(f, docString);
            }
        }
    }
}


/*------------------------------------------------------------------------*/
/** 標準出力に関数情報を表示
 *
 * @param r			[in] オブジェクト
 *
 * @return			なし
 */

void NewtInfo(newtRefArg r)
{
    newtStream_t	stream;
    
    NIOSetFile(&stream, stdout);
    NIOInfo(&stream, r);
}


/*------------------------------------------------------------------------*/
/** 標準出力に全グローバル関数の関数情報を表示
 *
 * @return			なし
 */

void NewtInfoGlobalFns(void)
{
    newtStream_t	stream;
    newtRef *	slots;
    newtRefVar	fns;
    uint32_t	len;
    uint32_t	i;
    
    NIOSetFile(&stream, stdout);
    
    fns = NcGetGlobalFns();
    len = NewtLength(fns);
    
    slots = NewtRefToSlots(fns);
    
    for (i = 0; i < len; i++)
    {
        NIOInfo(&stream, slots[i]);
    }
}

