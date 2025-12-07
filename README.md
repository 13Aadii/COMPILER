# Mini Compiler (Print + Math Expressions)

A small custom programming language implemented in C++ with a full compiler pipeline:
- **Lexer**
- **Parser**
- **AST**
- **Interpreter**

The language currently supports:

- `print <expression>;`
- Integer numbers
- Mathematical operations:
  - Addition (`+`)
  - Subtraction (`-`)
  - Multiplication (`*`)
  - Division (`/`)
- Parentheses for grouping expressions

---

## Language Examples

### Basic print:
```adi
print 30;
print 10 + 20;
print 2 + 3 * 4;
print (2 + 3) * 4;

---

## Grammar Rules (EBNF)

The grammar below defines the syntax of the language supported by this compiler.

### ✨ Precedence (Highest → Lowest)
1. **Factor**: numbers, grouped expressions `( )`
2. **Term**: multiplication and division (`*`, `/`)
3. **Expression**: addition and subtraction (`+`, `-`)

