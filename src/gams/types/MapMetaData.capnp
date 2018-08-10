# Generated by ./generate_schemas.py. This file should not be modified by hand.
@0xd977fc577e0fde62;

# Namespace setup
using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("gams::types");

# Capnfile Imports
using import "Pose.capnp".Pose;

# Type definition
struct MapMetaData {
   origin @0: Pose;
   width @1: UInt32;
   mapLoadTime @2: Int64;
   resolution @3: Float32;
   height @4: UInt32;
   
}
