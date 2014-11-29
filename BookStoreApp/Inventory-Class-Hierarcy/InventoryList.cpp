



#include "InventoryList.h"

InventoryList::InventoryList(): List(), DatabasePath(""){}






InventoryList::InventoryList( string name, string databasePath):
   List(name), DatabasePath(databasePath)
{

   this->BuildFromDatabase();

}




InventoryList::~InventoryList()
{

   cout << "\nInventory List " << ListName << " Destroyed\n";

}





void InventoryList::BuildFromDatabase()
{

   if( DatabasePath != "" )
   {

      ifstream inventoryFile(DatabasePath);
      string productType, author, title, genre, publisher, audioFormat, ebookFormat, buffer;
      int quanity, isbn, pageCount;
      double price;
      genreType bGenre;
      audioFileFormat abFormat;
      eBookFileFormat ebFormat;

      if ( !inventoryFile ) {
         cerr << "ERROR: Failed to open input file\n";
         exit(-1);
      }

      while ( getline (inventoryFile, buffer, ';'))
      {
         productType = buffer;

         getline (inventoryFile, buffer, ';');
         title = buffer;

         getline (inventoryFile, buffer, ';');
         author = buffer;

         getline (inventoryFile, buffer, ';');
         genre = buffer;
         Genre( bGenre, genre );

         getline (inventoryFile, buffer, ';');
         price = atof(buffer.c_str( ) );

         getline (inventoryFile, buffer, ';');
         quanity = atoi( buffer.c_str() );

         getline (inventoryFile, buffer, ';');
         isbn = atoi( buffer.c_str() );

         getline (inventoryFile, buffer, ';');
         publisher = buffer;

         if( productType == "Paper Book" )
         {
            getline (inventoryFile, buffer, '\n');
            pageCount = atoi( buffer.c_str() );
            ItemList[ItemCount] = new PaperBook(productType, quanity, price,
                                                isbn, author, title, bGenre,
                                                publisher, pageCount);
         }

         if( productType == "Audio Book" ){
            getline (inventoryFile, buffer, '\n');
            audioFormat = buffer;
            AudioFormat( abFormat, audioFormat );
            ItemList[ItemCount] = new AudioBook(productType, quanity, price,
                                            isbn, author, title, bGenre,
                                            publisher, abFormat);
         }

         if( productType == "eBook" ){
            getline (inventoryFile, buffer, '\n');
            ebookFormat = buffer;
            EbookFormat( ebFormat, ebookFormat );
            ItemList[ItemCount] = new eBook(productType, quanity, price, isbn,
                                            author, title, bGenre,
                                            publisher, ebFormat);
         }
         
         ++ItemCount;
      }
      
      inventoryFile.close();

   }
   else
   {

      cout << "\nDatabase Path not set\n";

   }
   
}


/*overwrties the templates RemoveFromList so it deletes the pointer as well*/
void InventoryList::RemoveFromList( Item* item )
{




}



Item* InventoryList::Search( string bookProperty )
{

   Item* tmpPointer = NULL;
   return tmpPointer;

}


Item* InventoryList::Search(int isbn)
{

   Item* tmpPointer = NULL;
   return tmpPointer;

}



void InventoryList::Genre(genreType& bGenre, string identifier)
{
   if( identifier == "Science Fiction" )
      bGenre = SCIENCE_FICTION;
   else if( identifier == "Mystery" )
      bGenre = MYSTERY;
   else if( identifier == "Horror" )
      bGenre = HORROR;
   else if( identifier == "Romance" )
      bGenre = ROMANCE;
   else
      bGenre = UNKNOWN;
}




void InventoryList::AudioFormat(audioFileFormat& abFormat, string identifier)
{
   if( identifier == "MP3" )
      abFormat = MP3;
   else
      abFormat = UNKNOWN_AUDIO;
}




void InventoryList::EbookFormat(eBookFileFormat& ebFormat, string identifier)
{
   if( identifier == "PDF" )
      ebFormat = PDF;
   else if( identifier == "EPUB" )
      ebFormat = EPUB;
   else
      ebFormat = UNKNOWN_EBOOK;
}





