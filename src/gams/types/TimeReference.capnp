# Generated by ./generate_schemas.py. This file should not be modified by hand.
@0xad8ebdbb629f1e43;

# Namespace setup
using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("gams::types");

# Capnfile Imports
using import "Header.capnp".Header;

# Type definition
struct TimeReference {
   header @0: Header;
   source @1: Text;
   timeRef @2: Int64;
   
}
