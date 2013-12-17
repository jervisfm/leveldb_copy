
#include <iostream>
#include <stdio.h>
using namespace std;

#include <assert.h>
#include "leveldb/db.h"


static leveldb::DB*  create_db() {
  leveldb::DB* db;
  leveldb::Options options;
  options.create_if_missing = true;
  leveldb::Status status = leveldb::DB::Open(options, "testdb", &db);
  assert(status.ok());
  cout << "success create DB !!!" << endl;
  return db;
}

static bool test_store(leveldb::DB* db) {
  string value = "bar value ";
  string key = "foo";
  leveldb::Status s = db->Put(leveldb::WriteOptions(), key, value);
  assert (s.ok());
  cout << "test store success" << endl;
  return s.ok();
}

static bool test_read(leveldb::DB* db) {
  string key ="foo";
  string value;
  leveldb::Status s = db->Get(leveldb::ReadOptions(), key, &value);
  assert ( value.size() > 0 );
  cout << "test read success: " << key << " -> " << value << endl; 
  return s.ok();
}

static bool test_delete(leveldb::DB* db) {
  string key = "foo";
  leveldb::Status s = db->Delete(leveldb::WriteOptions(), key);
  assert ( s.ok() );
  return s.ok();
}

int main (int argc, char ** argv) {
  cout << "Test Level DB Program" << endl; 
  leveldb::DB* db = create_db();
  test_store(db);
  test_read(db);
  test_delete(db);
  
  delete db;

  return 0;
}
