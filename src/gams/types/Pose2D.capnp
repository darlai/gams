# Generated by ./generate_schemas.py. This file should not be modified by hand.
@0xbce2dc23068b8600;

# Namespace setup
using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("gams::types");

# Capnfile Imports

# Type definition
struct Pose2D {
   y @0: Float64;
   x @1: Float64;
   theta @2: Float64;
   
}
