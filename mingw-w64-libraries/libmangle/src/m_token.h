/*
   Copyright (c) 2009-2016  mingw-w64 project

   Contributing authors: Kai Tietz, Jonathan Yong

   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.
*/
#ifndef _M_TOKEN_HXX
#define _M_TOKEN_HXX

/**
 * Garbage collector elements.
 * Tracks allocated memory and points to the next element from the same context.
 * @see libmangle_gc_context_t
 */
typedef struct sGcElem {
  struct sGcElem *chain;        /**< Next element in chain. */
  size_t length;                /**< Size of allocated memory (excluding sGcElem and sGcCtx). */
  char dta[1];                  /**< Starting adress marker of requested memory. */
} sGcElem;

/**
 * Garbage collector context.
 * Tracks first and last of elements in gc context.
 * @see libmangle_generate_gc()
 * @see libmangle_release_gc()
 */
typedef struct libmangle_gc_context_t {
  sGcElem *head;                /**< Pointer to first gc element in context.*/
  sGcElem *tail;                /**< Pointer to last gc element in context. */
} libmangle_gc_context_t;

/**
 * Token "Kind" enumeration list.
 * @see gen_tok()
 * @see eMSToken
 * @see sMToken_base
 */
typedef enum eMToken {
  eMToken_none = 0,                /**< Token type: None.  */
  eMToken_value = 1,               /**< Token type: Value. */
  eMToken_name = 2,                /**< Token type: Name.  */
  eMToken_dim = 3,                 /**< Token type: Dim.   */
  eMToken_unary = 4,               /**< Token type: Unary  */
  eMToken_binary = 5,              /**< Token type: Binary */
  eMToken_MAX                      /**< Unused sentinel.   */
} eMToken;

/**
 * Token "Subkind" enumeration list.
 * Also used by internal function sprint_decl1() for printing.
 * @see gen_tok()
 * @see eMToken
 * @see sMToken_base
 */
typedef enum eMSToken {
  eMST_unmangled = 0,               /**< Name is unmagled. */
  eMST_nttp = 1,                    /**< Template name. */
  eMST_name = 2,                    /**< Decoded function name. */
  eMST_colon = 3,                   /**< Class member accessibility. */
  eMST_rtti = 4,                    /**< Runtime Type information name. */
  eMST_cv = 5,                      /**< Function call convention / data qualifiers / pointer. */
  eMST_vftable = 6,                 /**< Virtual Function Table. */
  eMST_vbtable = 7,                 /**< Virtual Base Table. */
  eMST_vcall = 8,                   /**< Virtual Function Call. */
  eMST_opname = 9,                  /**< Overloaded operator. */
  eMST_templargname = 10,           /**< Explicit template arg name. */
  eMST_type = 11,                   /**< Function return type. */
  eMST_dim,                         /**< Print array-like expression. @see eMToken_dim */
  eMST_val,                         /**< Print value expression. @see sMToken_val */
  eMST_gcarray, /* __gc[,,,,] */    /**< MSVC extenstion: "__gc" Managed C++ reference. */
  eMST_slashed,                     /**< MTOKEN_UNARY appended and prepended with "/". */
  eMST_array,                       /**< MTOKEN_UNARY enclosed by square brackets. */
  eMST_element,                     /**< MTOKEN_UNARY in an argument list. */
  eMST_template_argument_list,      /**< MTOKEN_UNARY in an argument list. */
  eMST_ltgt,                        /**< MTOKEN_UNARY enclosed by angular brackets. */
  eMST_frame,                       /**< MTOKEN_UNARY enclosed by curly brackets. */
  eMST_throw,                       /**< MTOKEN_UNARY prepended by "throw ". */
  eMST_rframe,                      /**< MTOKEN_UNARY enclosed by parentheses. */
  eMST_destructor,                  /**< MTOKEN_UNARY prepended with "~". */
  eMST_oper,                        /**< indicates that token an operand, prints from MTOKEN_UNARY. */
  eMST_colonarray, /* ::[] */       /**< Unused, to be removed. */
  eMST_lexical_frame,               /**< MTOKEN_UNARY enclosed by single quotes "'". */
  eMST_scope,                       /**< MTOKEN_UNARY, unenclosed. */
  eMST_udt_returning,               /**< User defined types (RTTI). */
  eMST_coloncolon,                  /**< "::" between MTOKEN_BINARY_LEFT and MTOKEN_BINARY_RIGHT. */
  eMST_assign,                      /**< "=" between MTOKEN_BINARY_LEFT and MTOKEN_BINARY_RIGHT and appended with "}". */
  eMST_templateparam,               /**< Explicit template. */
  eMST_nonetypetemplateparam,       /**< Non-explicit template. */
  eMST_exp,                         /**< dim 'e' (exponent) dim */
  eMST_combine,                     /**< Unary grouping. */
  eMST_ecsu,                        /**< Is an Enum/Class/Struct/Union */
  eMST_based                       /**< MSVC extension: "__based" Based addressing */
} eMSToken;

/**
 * Token base descriptor header.
 * Descibes the type of token being processed.
 */
typedef struct sMToken_base {
  enum eMToken kind;            /**< Token kind. */
  enum eMSToken subkind;        /**< Token Subkind. */
  union uMToken *chain;         /**< Pointer to next token. NULL terminated. */
  int flags;                    /**< Token flags. */
} sMToken_base;

/**Sets the token kind, @a PT pointer to a base uMToken. */
#define MTOKEN_KIND(PT)		((PT)->base.kind)

/**Sets the token subkind, @a PT pointer to a base uMToken. */
#define MTOKEN_SUBKIND(PT)	((PT)->base.subkind)

/**Sets the pointer to the next token in the chain. */
#define MTOKEN_CHAIN(PT)	((PT)->base.chain)

/**Sets flags in base descriptor. */
#define MTOKEN_FLAGS(PT)	((PT)->base.flags)

#define MTOKEN_FLAGS_UDC    0x1 /**< Indicates a following "name" token for named struct/union/class. */
#define MTOKEN_FLAGS_NOTE   0x2 /**< Contains "note" name token.*/
#define MTOKEN_FLAGS_PTRREF 0x4 /**< Decoded fragment is a referrence. */
#define MTOKEN_FLAGS_ARRAY  0x8 /**< Decoded fragment has an array-like expression.*/

/**
 * "value" token.
 * Contains numerical expressions for decoded names.
 * @see sMToken_dim
 */
typedef struct sMToken_value {
  sMToken_base base;            /**< Base descriptor header. */
  uint64_t value;               /**< Integer value. */
  uint64_t size : 5;            /**< Byte width of value. */
  uint64_t is_signed : 1;       /**< Value signed bit */
} sMToken_value;

/**Sets the token value. @a PT pointer to a value uMToken.*/
#define MTOKEN_VALUE(PT)	((PT)->value.value)

/**Sets the signed bit on value token. @a PT pointer to a value uMToken.*/
#define MTOKEN_VALUE_SIGNED(PT)	((PT)->value.is_signed)

/**Sets the byte width of value in value token. @a PT pointer to a value uMToken.*/
#define MTOKEN_VALUE_SIZE(PT)	((PT)->value.size)

/**
 * "name" token.
 * Contains text string expressions of the decoded fragment.
 */
typedef struct sMToken_name {
  sMToken_base base;            /**< Base descriptor header. */
  char name[1];                 /**< Pointer to text string.*/
} sMToken_name;

/** Retrieve or set the name string, @a PT pointer to a name uMToken */
#define MTOKEN_NAME(PT)		((PT)->name.name)

/**
 * "dim" token.
 * Contains array-like expressions in decoded names.
 */
typedef struct sMToken_dim {
  sMToken_base base;            /**< Base descriptor header. */
  union uMToken *value;         /**< Pointer to value token. */
  union uMToken *non_tt_param;  /**< Pointer to C++ template name token. */
  int beNegate;                 /**< 1 for negative "values". */
} sMToken_dim;

/** Retrieve or set the value of a token, @a PT pointer to a value uMToken */
#define MTOKEN_DIM_VALUE(PT)	((PT)->dim.value)

/** Retrieve or set the template of a token, @a PT pointer to a name uMToken */
#define MTOKEN_DIM_NTTP(PT)	((PT)->dim.non_tt_param)

/** Retrieve or set negative bit on value token, @a PT pointer to an generic uMToken */
#define MTOKEN_DIM_NEGATE(PT)	((PT)->dim.beNegate)

/**
 * Unary node token.
 * Contains a pointer to a single generic leaf element.
 */
typedef struct sMToken_Unary
{
  sMToken_base base;            /**< Base descriptor header. */
  union uMToken *unary;         /**< Pointer to leaf element. */
} sMToken_Unary;

/**Sets the leaf element on a unary token, @a PT pointer to a unary uMToken. */
#define MTOKEN_UNARY(PT)	((PT)->unary.unary)

/** 
 * Binary node token.
 * Contains pointers to any 2 generic token instances as child node elements. 
 * May act as a connector for decoded C++ names.
 */
typedef struct sMToken_binary {
  sMToken_base base;            /**< Base descriptor header. */
  union uMToken *left;          /**< Left node element. */
  union uMToken *right;         /**< Right node element. */
} sMToken_binary;

/**Sets the left node on binary token, @a PT pointer to a binary uMToken. */
#define MTOKEN_BINARY_LEFT(PT)		((PT)->binary.left)

/**Sets the right node on binary token, @a PT pointer to a binary uMToken. */
#define MTOKEN_BINARY_RIGHT(PT)		((PT)->binary.right)

/**
 * Generic token instances.
 * Type of token determined by base descriptor in members.
 * Base descriptor header available in all members through type punning.
 * @see gen_tok()
 */
typedef union uMToken {
  sMToken_base base;        /**< Base descriptor header. */
  sMToken_value value;      /**< "value" token. */
  sMToken_name name;        /**< "name" token. */
  sMToken_dim dim;          /**< "dim" token */
  sMToken_Unary unary;      /**< Unary node token. */
  sMToken_binary binary;    /**< Binary node token. */
} uMToken;

/**
 * gen_tok constructs uMToken instances
 * Instances are destroyed with libmangle_release_gc().
 * @param[in] gc Pointer to garbage collection context.
 * @param[in] kind Kind of token to construct
 * @param[in] subkind Subkind of token to construct
 * @param[in] addend Additional byte padding at the end.
 * @see libmangle_release_gc()
 */
uMToken *libmangle_gen_tok (libmangle_gc_context_t *gc, enum eMToken kind, enum eMSToken subkind, size_t addend);

/**
 * Releases memory tracked by context.
 * @param[in] gc Garbage collection context to work on.
 * @see libmangle_generate_gc()
 */
void libmangle_release_gc (libmangle_gc_context_t *gc);

/**
 * Constructs a garbage collection context token.
 * @return Pointer to context.
 * @see libmangle_release_gc()
 */
libmangle_gc_context_t *libmangle_generate_gc (void);

/**
 * Chains uMTokens together.
 * @param[in] l uMtoken chain to link up with.
 * @param[in] add uMtoken to add to chain.
 * @return @a l unchanged
 */
uMToken *chain_tok (uMToken *l, uMToken *add);

/**
 * Dumps uMToken to a file descriptor for debugging.
 * @param[in] fp File descriptor to print the token to.
 * @param[in] p uMToken chain to print.
 */
void libmangle_dump_tok (FILE *fp, uMToken *p);

/** 
 * Prints C++ name to file descriptor.
 * @param[in] fp Output file descriptor.
 * @param[in] p Token containing information about the C++ name.
 * @see libmangle_decode_ms_name()
 */
void libmangle_print_decl (FILE *fp, uMToken *p);

/** 
 * Get pointer to decoded C++ name string.
 * Use free() to release returned string.
 * @param[in] r C++ name token.
 * @return pointer to decoded C++ name string.
 * @see libmangle_decode_ms_name()
 */
char *libmangle_sprint_decl (uMToken *r);

/**
 * Constructs a "value" kind token.
 * @param[in] gc Pointer to garbage collection context.
 * @param[in] skind Token subkind.
 * @param[in] val Sets the value on token,
 * @param[in] is_signed Signed bit of \a val.
 * @param[in] size Width of \a val.
 * @return Pointer to value token.
 * @see sMToken_value
 */
uMToken *gen_value (libmangle_gc_context_t *gc, enum eMSToken skind, uint64_t val, int is_signed, int size);

/**
 * Constructs a "name" kind token.
 * @param[in] gc Pointer to garbage collection context.
 * @param[in] skind Token subkind.
 * @param[in] name Pointer to name string.
 * @return Pointer to name token.
 * @see sMToken_name
 */
uMToken *gen_name (libmangle_gc_context_t *gc, enum eMSToken skind, const char *name);

/**
 * Constructs a "dim" kind token.
 * @param[in] gc Pointer to garbage collection context.
 * @param[in] skind Token subkind.
 * @param[in] val Token numerical value.
 * @param[in] non_tt_param pointer to decoded C++ template name.
 * @param[in] fSigned Signedness of the numerical value.
 * @param[in] fNegate 1 for "val" is negative digit.
 * @return Pointer to dim token.
 * @see sMToken_dim
 */
uMToken *gen_dim (libmangle_gc_context_t *gc, enum eMSToken skind, uint64_t val, const char *non_tt_param, int fSigned, int fNegate);

/**
 * Constructs a "unary" kind token.
 * @param[in] gc Pointer to garbage collection context.
 * @param[in] skind Token subkind.
 * @param[in] un Pointer to leaf element.
 * @return Pointer to a unary token.
 * @see sMToken_unary
 */
uMToken *gen_unary (libmangle_gc_context_t *gc, enum eMSToken skind, uMToken *un);

/**
 * Generates a binary node token.
 * @param[in] gc Pointer to garbage collection context.
 * @param[in] skind Token subKind.
 * @param[in] l Left node element.
 * @param[in] r Right node element.
 * @return Pointer to binary token.
 * @see sMToken_binary
 */
uMToken *gen_binary (libmangle_gc_context_t *gc, enum eMSToken skind, uMToken *l, uMToken *r);

#endif
