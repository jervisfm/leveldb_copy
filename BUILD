[
  { "make": {
    "name": "leveldb_make",
    "make_target": "all", 
    //"pass_flags": "basic",
    //"outs": [ "$GEN_DIR/lib/libleveldb.a" ],
    "outs": [ "libleveldb.a" ],
    "licenses": [ "http://opensource.org/licenses/BSD-3-Clause" ]
  } },

  { "cc_library": {
    "name": "leveldb",
    "cc_headers": [ "include/leveldb/*.h"
    
    ],
    "cc_objects": [
    // "$GEN_DIR/lib/libleveldb.a",
    "libleveldb.a" 
    ],
    "dependencies": [ ":leveldb_make" ],
    "strict_file_mode": false,
    "cc_include_dirs": [ "include" ],
    "include_dirs": [ "include" ]
  } },

  { "cc_test": {
    "name": "testinstall",
    "cc_sources": [ "test.cc" ],
    "dependencies": [ ":leveldb" ]
  } }
]