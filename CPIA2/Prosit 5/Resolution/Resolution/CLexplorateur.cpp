#include "CLexplorateur.h"
#include "errorMessages.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

namespace NS_composants
{
	array<String^>^ CLfichier::explorerUnDossier(String^ dossier)
	{
		try
		{
			// Utilise Directory::GetFiles pour obtenir la liste des fichiers dans le dossier
			List<String^>^ fichiers = gcnew List<String^>();
			for each (String ^ toTest in Directory::GetFiles(dossier)) {
				toTest = toTest->ToLower();
				if (!toTest->EndsWith(".jpeg") && !toTest->EndsWith(".png") && !toTest->EndsWith(".jpg")
					&& !toTest->EndsWith(".webp") && !toTest->EndsWith(".bmp") && !toTest->EndsWith(".tiff")
					|| System::IO::File::GetAttributes(toTest) == FileAttributes::Directory) continue;
				fichiers->Add(toTest);
			}
			return fichiers->ToArray();
		}
		catch (Exception^ ex)
		{
			// Gérer l'exception ici, par exemple, afficher un message d'erreur
			showErrorMessage("Erreur lors de l'exploration du dossier : " + ex->Message);
			return nullptr;
		}
	}
	void CLfichier::effacer(String^ fichier)
	{
		System::IO::File::Delete(fichier);
	}
	void CLfichier::copier(String^ fichierSource, String^ fichierDestination)
	{
		String^ nomDeFichierExtension;
		nomDeFichierExtension = System::IO::Path::GetFileName(fichierSource);
		System::IO::File::Copy(fichierSource, fichierDestination + "\\" + nomDeFichierExtension);
	}
}
