#include "CLimages.h"
#include "errorMessages.h"

using namespace System;

namespace NS_composants
{
    System::Drawing::Bitmap^ CLimages::acquisitionImage(String^ fichier)
    {
        try{
            return fichier == "" ? nullptr : gcnew System::Drawing::Bitmap(fichier);
        }
        catch (System::Exception^ ex){
            showErrorMessage("Impossible d'ouvrir la photo suivante : " + fichier);
            return nullptr;
        }
    }

}
