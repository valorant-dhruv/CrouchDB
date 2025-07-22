#include<stdio.h>
#include<stdlib.h>
#include "./db_instance_headers.h"
#include <time.h>
#include <string.h>

// Function to generate a unique ID using timestamp and randomness
static int generate_unique_id() {
  //We take the current timestamp and some randomness and XOR them to generate a unique ID
  int current_timestamp = (int)time(NULL);
  int random_number = rand();
  return current_timestamp ^ random_number;
}

//Function to create a new database instance and assign name and id to it
static Database_Instance *create_instance(char *db_instance_name)
{
  //We first assign some memory to the DB instance
  Database_Instance *db_instance =  malloc(sizeof(Database_Instance));
  
  //In case the mallod assignment fails
  if (db_instance == NULL) return NULL;

  //Now we assign the name and ID to the newly created database instance
  db_instance -> id = generate_unique_id();
  db_instance -> db_instance_name = db_instance_name;

  return db_instance;
}

static void add_instance_to_hashmap(char *name, Database_Instance *instance) {
  Database_Instance_Map_Entry *entry = malloc(sizeof(Database_Instance_Map_Entry));

  if(entry == NULL)
  {
    printf("Failed to create an entry for the hashmap\n");
    return;
  }

  entry->db_instance_name = strdup(name);
  entry->db_instance = instance;
}


int main(int argc, char *argv[])
{ 
  if(argc < 2)
  {
    printf("Invalid number of arguments\n");
    exit(1);
  }

  printf("Creating a new database instance\n");
  printf("================================\n");

  char *db_instance_name = argv[1];

  //Creating a new instance
  Database_Instance *db_instance = create_instance(db_instance_name);
  printf("This is the name of the newly created database instance: %s\n",db_instance->db_instance_name);
  printf("This is the ID of the newly created database instance: %d\n",db_instance -> id);

  //Storing the database instance name and pointer to the database instance 
  add_instance_to_hashmap(db_instance_name,db_instance);
  save_instance_hashmap_entry()

  free(db_instance);
  db_instance = NULL;
  exit(0);
}