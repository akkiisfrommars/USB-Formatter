
#include <iostream>
#include <cstdlib>
#include <unistd.h>

using namespace std;
int main() {
    string disk,confirm,choice,newdiskname,type;
    cout << "USB Formatter (Beta)" << endl;
    cout << "Created by akkiisfrommars" << endl;
    cout << "---------------------------" << endl;
    cout << "Loading available volumes..." << endl;
    sleep(3);
    string avlvol = "diskutil list";
    system(avlvol.c_str());
    cout << "Enter disk location: ";
    cin >> disk;
    cout << endl;

    cout << "Unmounting the disk..." << endl;
    sleep(1);
    string umount = "diskutil unmountDisk " + disk;
    int umountResult = system(umount.c_str());
    if (umountResult !=0) {
        cerr << "Failed to unmount disk :(" << endl;
        cout << "Reloading..." << endl;
        main();
    }
    else{
        cout << "Unmounting successful, proceeding..." << endl;
    }
    
    
    cout << "Enter name of formatted disk: ";
    cin >> newdiskname;
    
    
    cout << endl << "Format options" << endl;
    cout << "1) APFS" << endl;
    cout << "2) ExFAT" << endl;
    cout << "3) JHFS+" << endl;
    cout << "4) FAT32 " << endl;
    cout << "5) NTFS" << endl;
    cout << "6) UFS" << endl;
    cout << "7) FAT" << endl;
   cout << "More coming soon..." << endl;
    
    

    cout << "Format option: ";
    cin >> choice;

    if(choice == "1"){
        type = "APFS";
    }
    else if (choice == "2"){
        type = "ExFAT";
    }
    else if (choice == "3"){
        type = "JHFS+";
    }
    else if (choice == "4"){
        type = "FAT32";
    }
    else if (choice == "5"){
        type = "NTFS";
    }
    else if (choice == "6"){
        type = "UFS";
    }
    else if (choice == "7"){
        type = "MS-DOS";
    }
    else{
        cout << "Please enter a valid option..." << endl;
        main();
    }
    
    
    
    
    
    cout << "Formatting the disk " << disk << " as " << type << "..." << endl;
    cout << "All data on this disk will be erased ";
    cout << "Are you sure you want to continue? (y/N) ";
    cin >> confirm;
    
    
    
    
    if (confirm == "y" || confirm == "Y") {
        string format = "diskutil eraseDisk " + type + " " + newdiskname + " " + disk;
        cout << format << endl;
        // diskutil eraseDisk JHFS+ NewDiskName /dev/diskX
        
        int formatResult = system(format.c_str());
        
        if(formatResult != 0){
            cerr << "Error formatting disk :(" << endl;
            cout << "Reloading..." << endl;
            main();
        }
        else{
            
            cout << "Format complete, verifying..." << endl;
            string verify = "diskutil verifyDisk " + disk;
            system(verify.c_str());
            

            
            cout << endl << "Format successful" << endl << endl;
            
        }
        
    }
    
    else{
        cout << "Abort" << endl << endl;
    }
    
    
    return 0;
}
