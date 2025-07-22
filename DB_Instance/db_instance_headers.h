#define DB_INSTANCE_SIZE 16 //This means that each DB instance is of 16MB in size.

typedef struct
{
  int id;
  char *db_instance_name;
  char size[DB_INSTANCE_SIZE];
} Database_Instance;


typedef struct {
    char *db_instance_name;           
    Database_Instance *db_instance;   
} Database_Instance_Map_Entry;

