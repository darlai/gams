# Generated by ./generate_schemas.py. This file should not be modified by hand.
@0xf32005189246089e;

# Namespace setup
using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("gams::types");

# Capnfile Imports

# Type definition
struct Point32 {
   y @0: Float32;
   x @1: Float32;
   z @2: Float32;
   
}
