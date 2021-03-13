/* src/version.h.  Generated from version.h.in by configure.  */
/*------------------------------------------------------------------------*/
/**
 * @file	version.h
 * @brief   バージョン情報
 *
 * @author  M.Nukui
 * @date	2003-11-07
 *
 * Copyright (C) 2003-2020 M.Nukui All rights reserved.
 */


#ifndef	NEWTVERSION_H
#define	NEWTVERSION_H


#define PROJECT_NAME "@PROJECT_NAME@"
#define PROJECT_VER  "@PROJECT_VERSION@"
#define PROJECT_VER_MAJOR "@PROJECT_VERSION_MAJOR@"
#define PROJECT_VER_MINOR "@PROJECT_VERSION_MINOR@"
#define PROJECT_VER_PATCH "@PROJECT_VERSION_PATCH@"

#define COMPILE_TIME_YYYY @COMPILE_TIME_YYYY@
#define COMPILE_TIME_MM @COMPILE_TIME_MM@
#define COMPILE_TIME_DD @COMPILE_TIME_DD@


/* マクロ定義 */
#define NEWT_NAME		"newt"									///< コマンド名
#define NEWT_PROTO		"/0"									///< プロト

#ifndef NEWT_VERSION
#define NEWT_VERSION	"v" PROJECT_VER							///< バージョン
#endif

#ifndef NEWT_BUILD
#define NEWT_BUILD		"----"									///< ビルド番号
#endif


#define NEWT_COPYRIGHT	"Copyright (C) 2003-2020 Makoto Nukui and others"  ///< コピーライト
#define NEWT_PARAMS		"[switches] [--] [programfile]"			///< 引数

/// 使用方法
#define NEWT_USAGE		"  -t              enable trace mode\n"			\
						"  -l              dump lex info\n"				\
						"  -s              dump syntax tree\n"			\
						"  -b              dump byte code\n"			\
						"  -C directory    change working directory\n"	\
						"  -e 'command'    one line of script\n"		\
						"  -i [symbols]    print function info\n"		\
						"  -v              print version number\n"		\
						"  -h              print this help message\n"	\
						"  --newton,--nos2 Newton OS 2.0 compatible	\n"	\
						"  --copyright     print copyright\n"			\
						"  --version       print version number\n"		\
						"  --staff         list of developers\n"

/// スタッフロール
#define NEWT_STAFF		"Program\n"										\
                        "  Makoto Nukui\n"								\
                        "\n"											\
                        "Contribute\n"									\
                        "  Paul Guyot\n"								\
                        "  Matthias Melcher\n"							\
                        "\n"											\
                        "Special Thanks\n"								\
                        "  sumim\n"										\
                        "  Rihatsu\n"									\
						""

#endif /* NEWTVERSION_H */
