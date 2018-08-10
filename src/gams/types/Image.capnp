# Generated by ./generate_schemas.py. This file should not be modified by hand.
@0xa0575cdfd1758ffc;

# Namespace setup
using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("gams::types");

# Capnfile Imports
using import "Header.capnp".Header;

# Type definition
struct Image {
   encoding @0: Text;
   height @1: UInt32;
   header @2: Header;
   step @3: UInt32;
   data @4: List(UInt8);
   width @5: UInt32;
   isBigendian @6: UInt8;
   
}
