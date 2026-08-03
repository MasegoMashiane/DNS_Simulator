#ifndef DNS_TYPES_H //header gaurd
#define DNS_TYPES_H

// Repsonsibility of DNSTypes.h
// Contains fundamental types that are shared across the project
// DNS Record types, DNS query classes, DNS response codes, 
// common constants,type aliases
// All are types, not behaviour

namespace dns{
    // DNS resource record types
    enum class RecordType // strongly typed/ scoped enumeration
                        // Provides type safety and clean scoping
                        // For enum constants.
                        // Traditional enums can implicitly leak 
                        // their named values into the sorounding code
                        // and behave exactly like integers.
    {                       
        A,
        AAAA,
        CNAME,
        MX,
        NS,
        TXT
    };

    // DNS operetion Codes
    enum class OpCode
    {
        Query, 
        IQuery,
        Status
    };

    // DNS response codes
    enum class ResponseCode
    {
        noError,
        FormatError,
        ServerFailure,
        NameError,
        NotImplemented,
        Refused
    };
}

#endif
// ifdef: Is a preprocessor directive that means “if defined”.
// It checks whether a macro name has been defined earlier with #define.
// If the macro exists, the code between #ifdef and the matching #endif 
// is kept.
// If the macro does not exist, that block is skipped before compilation.

// ifndef: means “if not defined”.
// It checks whether a macro name has not been defined yet.
// If the macro is not defined, the code between #ifndef and #endif is included.
// If the macro is already defined, that block is skipped.

// Prevents multiple inclusion of the same header file.
// Helps avoid duplicate definitions and compile errors.
// Enables conditional compilation for platform-specific or optional code.



// Enums: User-defined data type used to assign huma-readable names to a 
// collection of named constants. 
// The fix confusing cryptic numbers/strings with descriptive names
// meaningful labels, while also preventing invalid values from being assigned
// making source code cleaner, self-documenting and easier to
// maintain.

// Modern c++ Provides two type of enums
// Scoped Enums (Enum class) and Unscoped Enums (Enum)