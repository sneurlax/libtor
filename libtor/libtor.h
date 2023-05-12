#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>


/**
 * Error enum
 */
typedef struct Error Error;

typedef struct Result_u8__Error Result_u8__Error;

typedef struct String String;

/**
 * Configuration builder for a Tor daemon
 *
 * Offers the ability to set multiple flags and then start the daemon either in the current
 * thread, or in a new one
 */
typedef struct Tor Tor;

/**
 * Enum that represents a subset of the options supported by Tor
 *
 * Generally speaking, all the server-only features have not been mapped since this crate is
 * targeted more to a client-like usage. Arbitrary flags can still be added using the
 * `TorFlag::Custom(String)` variant.
 */
typedef struct TorFlag TorFlag;

/**
 * Add a configuration flag
 */
struct Tor *flag(struct Tor *self, struct TorFlag flag);

/**
 * Generate a hashed password to use HashedControlPassword
 */
struct String generate_hashed_password(const str *secret);

/**
 * Create a new instance
 */
struct Tor new(void);

/**
 * Start the Tor daemon in the current thread
 */
struct Result_u8__Error start(const struct Tor *self);

/**
 * Starts the Tor daemon in a background detached thread and return its handle
 */
JoinHandle<Result<uint8_t, Error>> start_background(const struct Tor *self);
