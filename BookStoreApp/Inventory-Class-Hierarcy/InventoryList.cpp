



#include "InventoryList.h"

InventoryList::InventoryList(): List(), DatabasePath(""){}






InventoryList::InventoryList( string name, string databasePath):
   List(name), DatabasePath(databasePath)
{

   this->BuildFromDatabase();

}




InventoryList::~InventoryList()
{
   ofstream out("inventorylistout.txt",ios::trunc);
   
   if ((dynamic_cast<eBook *>(this)) != NULL){
      eBook* p = dynamic_cast<eBook *>(this);
      out << "eBook;" << p->getTitle()
         << ";" << p->getAuthor()
         << ";" << p->getGenre()
         << ";" << p->GetPrice()
         << ";" << "NULL"
         << ";" << p->getISBN()   
         << ";" << p->getPublisher()
         << ";" << p->getFileFormat() << endl;
   }
   else if (dynamic_cast<PaperBook *>(this) != NULL){
      PaperBook* p = dynamic_cast<PaperBook*>(this);
      out << "Paper Book;" << p->getTitle()
         << ";" << p->getAuthor()
         << ";" << p->getGenre()
         << ";" << p->GetPrice()
         << ";" << p->getQuantity()
         << ";" << p->getISBN()
         << ";" << p->getPublisher()
         << ";" << p->getNumberOfPages() << endl;
      
   }
   else if (dynamic_cast<AudioBook*>(this) != NULL){
      AudioBook* p = dynamic_cast<AudioBook*>(this);
      out << "Audio Book;" << p->getTitle()
         << ";" << p->getAuthor()
         << ";" << p->getGenre()
         << ";" << p->GetPrice()
         << ";" << p->getQuantity()
         << ";" << p->getISBN()
         << ";" << p->getPublisher()
         << ";" << p->getAudioFormat() << endl;
   }
   
   out.close();

}

string Name, int Quantity, double Price,
int ISBN, string author, string title,
genreType genre, string publisher, eBookFileFormat fileFormat

eBook * eb = dynamic_cast<eBook *>(*p);
PaperBook * pb = dynamic_cast<PaperBook *>(*p)&
AudioBook * ab = dynamic_cast<AudioBook *>(*p);


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

      while ( getline (inventoryFile, buffer, ';') )
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
            AddToList( new PaperBook(productType, quanity, price,
                                     isbn, author, title, bGenre,
                                     publisher, pageCount) );

         }
         else if( productType == "Audio Book" ){
            getline (inventoryFile, buffer, '\n');
            audioFormat = buffer;
            AudioFormat( abFormat, audioFormat );
            AddToList( new AudioBook(productType, quanity, price,
                                     isbn, author, title, bGenre,
                                     publisher, abFormat) );

         }
         else if( productType == "eBook" ){
            getline (inventoryFile, buffer, '\n');
            ebookFormat = buffer;
            EbookFormat( ebFormat, ebookFormat );
            AddToList( new eBook(productType, quanity, price, isbn,
                                 author, title, bGenre,
                                 publisher, ebFormat) );

         }else
            AddToList( NULL);
         
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

   for( p = ItemList.begin(); p != ItemList.end(); p++ )
   {
      if(*p == item)
      {
         delete *p;
         ItemList.erase(p);
         --ItemCount;
      }
   }

}



vector<Item*> InventoryList::Search( string bookProperty )
{

   vector<Item*> temp;

   for( p = ItemList.begin(); p != ItemList.end(); p++ )
   {
      eBook * eb = dynamic_cast<eBook *>(*p);
      PaperBook * pb = dynamic_cast<PaperBook *>(*p);
      AudioBook * ab = dynamic_cast<AudioBook *>(*p);

      if( (eb && eb->getTitle() == bookProperty) || (eb && eb->getAuthor() == bookProperty) )
      {

         temp.push_back( eb );
         
      }
      else if( (pb && pb->getTitle() == bookProperty) || (pb && pb->getAuthor() == bookProperty) )
      {

         temp.push_back( pb );

      }
      else if( (ab && ab->getTitle() == bookProperty) || (ab && ab->getAuthor() == bookProperty) )
      {

         temp.push_back( ab );

      }


   }

   return temp;

}



vector<Item*> InventoryList::Search( int isbn )
{

   vector<Item*> temp;

   for( p = ItemList.begin(); p != ItemList.end(); p++ )
   {
      eBook * eb = dynamic_cast<eBook *>(*p);
      PaperBook * pb = dynamic_cast<PaperBook *>(*p);
      AudioBook * ab = dynamic_cast<AudioBook *>(*p);

      if( eb && eb->getISBN() == isbn )
      {

         temp.push_back( eb );

      }
      else if( pb && pb->getISBN() == isbn )
      {

         temp.push_back( pb );

      }
      else if( ab && ab->getISBN() == isbn )
      {

         temp.push_back( ab );
         
      }
      
      
   }
   
   return temp;
   
}

// insert SearchID
Item * InventoryList::SearchID(int ID)
{
   for (int i = 0; i < ItemCount; i++)
   {
      if (GetElementAtPosI(i)->GetID() == ID)
         return GetElementAtPosI(i);
      else
      cout << "Item ID doesnt exist";
   }
   return NULL;
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



void InventoryList::SetDatabasePath( string path )
{

   DatabasePath = path;

}




string InventoryList::GetDatabasePath() const
{

   return DatabasePath;
   
}




