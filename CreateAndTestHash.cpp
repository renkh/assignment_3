/*****************************************************************************
  Title          : CreateAndTestHash.cpp
  Author         : Renat Khalikov
  Created on     : April 06, 2017
  Description    : main for parts 1 and 2 of Assignment 3
  Purpose        : To test three hashing implementations: linear probing,
                   quadratic probing, and double probing.
  Usage          : ./CreateAndTestHash <words_filename> <query_filename> <flag>
  Build with     : make all, by using the included make file
*/
#include "QuadraticProbing.h"
#include "LinearProbing.h"
#include "DoubleHashing.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // exit(1) call
using namespace std;

// InsertWordsIntoHashTable() opens words_filename and inserts the words
// into a hash table. The type of hash table, specified by hash_table, could
// be linear, quadratic, or double probing. 
//
// @hash_table: object containing either linear, quadratic, or double probing
//              hash table
// @words_filename: user supplied file containing words to be inserted into
//                  hash_table
// return: none, hash_table contains words from words_filename
template <typename HashTableType>
void InsertWordsIntoHashTable( HashTableType &hash_table, const string &words_filename ) {
  string word_in_file;
  ifstream input_words_filename(words_filename);
  if (input_words_filename.fail()) {
    cerr << "Could not open <words_filename>\n";
    exit(1); // 1 indicates an error occurred
  }
  while ( input_words_filename >> word_in_file ) {
    hash_table.Insert(word_in_file);
  }
  input_words_filename.close();
}

// CheckWordInQueryFile() opens and parces query_filename. Prints the words
// that match the words in hash_table, counts and prints total number of
// collisions 
//
// @hash_table: object containing either linear, quadratic, or double probing
//              hash table
// @query_filename: user supplied file containing words to be searched in
//                  hash_table
// return: none, prints the word in query_filename that matches word in 
//         hash_table
template <typename HashTableType>
void CheckWordInQueryFile( HashTableType &hash_table, const string &query_filename ) {
  string word_in_file;
  ifstream input_query_filename(query_filename);
  if (input_query_filename.fail()) {
    cerr << "Could not open <query_filename>\n";
    exit(1); // 1 indicates an error occurred
  }
  size_t total_number_of_collisions;
  while ( input_query_filename >> word_in_file ) {
    hash_table.resetCollisions();
    if ( hash_table.Contains(word_in_file) ) {
      hash_table.getTotalNumberOfCollisions( total_number_of_collisions );
      cout << word_in_file << " Found " << total_number_of_collisions+1 << endl;
    }
    else if ( !hash_table.Contains(word_in_file) ){
      hash_table.getTotalNumberOfCollisions( total_number_of_collisions );
      cout << word_in_file << " Not Found " << total_number_of_collisions+1 << endl;
    }
  }
  input_query_filename.close();
}

// TestFunctionForHashTable() inserts words from words_filename into hash_table
// outputs total number of collisions, total number of elements in the table
// size of table, load factor, average number of collisions, and calls 
// CheckWordInQueryFile()
//
// @hash_table: object containing either linear, quadratic, or double probing
//              hash table
// @words_filename: user supplied file containing words to be inserted into
//                  hash_table
// @query_filename: user supplied file containing words to be searched in
//                  hash_table
// return: none, prints the word in query_filename that matches word in 
//         hash_table
template <typename HashTableType>
void TestFunctionForHashTable(HashTableType &hash_table, const string &words_filename, const string &query_filename) {
  cout << "TestFunctionForHashTables..." << endl;
  cout << "Words filename: " << words_filename << endl;
  cout << "Query filename: " << query_filename << endl;
  hash_table.MakeEmpty();  
  //..Insert your own code
  // PART 1
  InsertWordsIntoHashTable( hash_table, words_filename );

  size_t total_number_of_collisions;
  hash_table.getTotalNumberOfCollisions( total_number_of_collisions );
  cout << "Collisions: " << total_number_of_collisions << endl;

  double total_number_of_elements_in_the_table = hash_table.getTotalNumberOfElements( );
  cout << "Number of items: " << total_number_of_elements_in_the_table << endl;

  double size_of_table = hash_table.getTotalSizeOfTable( );
  cout << "Size of hash table: " << size_of_table << endl;
  cout << "Load factor: " << total_number_of_elements_in_the_table / size_of_table << endl;
  cout << "Avg. number of collisions: " << total_number_of_collisions / total_number_of_elements_in_the_table << endl;

  // PART 2
  CheckWordInQueryFile( hash_table, query_filename );
}

// Sample main for program CreateAndTestHash
int main(int argc, char **argv) {
  if (argc != 4) {
    cout << "Usage: " << argv[0] << " <wordsfilename> <queryfilename> <flag>" << endl;
    return 0;
  }
  
  const string words_filename(argv[1]);
  const string query_filename(argv[2]);
  const string param_flag(argv[3]);

  if (param_flag == "linear") {
    HashTableLinear<string> linear_probing_table;
    TestFunctionForHashTable(linear_probing_table, words_filename, query_filename);    
  } else if (param_flag == "quadratic") {
    HashTable<string> quadratic_probing_table;
    TestFunctionForHashTable(quadratic_probing_table, words_filename, query_filename);    
  } else if (param_flag == "double") {
    HashTableDouble<string> double_probing_table;
    TestFunctionForHashTable(double_probing_table, words_filename, query_filename);    
  } else {
    cout << "Uknown tree type " << param_flag << " (User should provide linear, quadratic, or double)" << endl;
  }
  return 0;
}
