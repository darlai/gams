# Generated by ./generate_schemas.py. This file should not be modified by hand.
@0xa049f1d9859b145b;

# Namespace setup
using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("gams::types");

# Capnfile Imports
using import "PoseStamped.capnp".PoseStamped;
using import "Header.capnp".Header;

# Type definition
struct Path {
   header @0: Header;
   poses @1: List(PoseStamped);
   
}
