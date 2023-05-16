#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>


/// Error enum
struct Error;

template<typename T = void, typename E = void>
struct Result;

struct String;

/// Configuration builder for a Tor daemon
///
/// Offers the ability to set multiple flags and then start the daemon either in the current
/// thread, or in a new one
struct Tor;

/// Enum that represents a subset of the options supported by Tor
///
/// Generally speaking, all the server-only features have not been mapped since this crate is
/// targeted more to a client-like usage. Arbitrary flags can still be added using the
/// `TorFlag::Custom(String)` variant.
struct TorFlag;


extern "C" {

/// Add a configuration flag
Tor *flag(Tor *self, TorFlag flag);

/// Generate a hashed password to use HashedControlPassword
String generate_hashed_password(const str *secret);

/// Create a new instance
Tor new();

/// Start the Tor daemon in the current thread
Result<uint8_t, Error> start(const Tor *self);

/// Starts the Tor daemon in a background detached thread and return its handle
JoinHandle<Result<uint8_t, Error>> start_background(const Tor *self);

} // extern "C"
