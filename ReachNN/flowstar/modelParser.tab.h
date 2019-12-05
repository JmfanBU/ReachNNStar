/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_MODELPARSER_TAB_H_INCLUDED
# define YY_YY_MODELPARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    IDENT = 259,
    STATEVAR = 260,
    TMVAR = 261,
    TM = 262,
    EQ = 263,
    GEQ = 264,
    LEQ = 265,
    ASSIGN = 266,
    END = 267,
    MODE = 268,
    INIT = 269,
    BELONGSTO = 270,
    PARAAGGREG = 271,
    INTAGGREG = 272,
    TMAGGREG = 273,
    OUTPUT = 274,
    NOOUTPUT = 275,
    CONTINUOUS = 276,
    HYBRID = 277,
    SETTING = 278,
    FIXEDST = 279,
    FIXEDORD = 280,
    ADAPTIVEST = 281,
    ADAPTIVEORD = 282,
    ORDER = 283,
    MIN = 284,
    MAX = 285,
    REMEST = 286,
    INTERVAL = 287,
    OCTAGON = 288,
    GRID = 289,
    PLOT = 290,
    QRPRECOND = 291,
    IDPRECOND = 292,
    TIME = 293,
    MODES = 294,
    JUMPS = 295,
    INV = 296,
    GUARD = 297,
    RESET = 298,
    START = 299,
    MAXJMPS = 300,
    PRINTON = 301,
    PRINTOFF = 302,
    UNSAFESET = 303,
    CONTINUOUSFLOW = 304,
    HYBRIDFLOW = 305,
    TAYLOR_PICARD = 306,
    TAYLOR_REMAINDER = 307,
    TAYLOR_POLYNOMIAL = 308,
    EXP = 309,
    SIN = 310,
    COS = 311,
    LOG = 312,
    SQRT = 313,
    ODE = 314,
    CUTOFF = 315,
    PRECISION = 316,
    GNUPLOT = 317,
    MATLAB = 318,
    COMPUTATIONPATHS = 319,
    LTIODE = 320,
    LTVODE = 321,
    PAR = 322,
    UNC = 323,
    UNIVARIATE_POLYNOMIAL = 324,
    MULTIVARIATE_POLYNOMIAL = 325,
    TIME_INV = 326,
    TIME_VAR = 327,
    STEP = 328,
    TRUE = 329,
    FALSE = 330,
    LINEARCONTINUOUSFLOW = 331,
    EXPRESSION = 332,
    MATRIX = 333,
    uminus = 334
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 31 "modelParser.y" /* yacc.c:1909  */

	double															dblVal;
	int																intVal;
	std::string														*identifier;
	std::vector<flowstar::Interval>									*intVec;
	std::vector<std::vector<flowstar::Interval> >					*intsVec;
	flowstar::Polynomial<flowstar::Interval>						*intPoly;
	flowstar::Polynomial<flowstar::Real>							*realPoly;
	flowstar::UnivariatePolynomial<flowstar::Real>					*uniPoly;
	std::vector<flowstar::Polynomial<flowstar::Interval> >			*intPolyVec;
	std::vector<flowstar::UnivariatePolynomial<flowstar::Real> >	*uniPolyVec;
	std::vector<flowstar::Flowpipe>									*flowpipeVec;
	std::vector<flowstar::Constraint>								*constraintVec;
	flowstar::TaylorModelVec<flowstar::Real>						*taylorModelVec;
	flowstar::Expression_AST<flowstar::Interval>					*pIntExpression;
	std::vector<flowstar::Expression_AST<flowstar::Interval> >		*intExpressionVec;
	LTI_Term														*pLTITerm;
	LTI_ODE_description												*pLTIDescription;
	LTV_Term														*pLTVTerm;
	LTV_ODE_description												*pLTVDescription;

#line 156 "modelParser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MODELPARSER_TAB_H_INCLUDED  */
