#include "errorMessages.h"

#include <msclr/marshal.h>  // Pour utiliser PtrToStringChars

void showErrorMessage(System::String^ toShow) {
	pin_ptr<const wchar_t> wch = PtrToStringChars(toShow);
	System::Windows::Forms::MessageBox::Show(gcnew System::String(wch), "Erreur",
		System::Windows::Forms::MessageBoxButtons::OK,
		System::Windows::Forms::MessageBoxIcon::Error);
}