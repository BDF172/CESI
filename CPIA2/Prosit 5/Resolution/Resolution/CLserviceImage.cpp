#include "CLserviceImage.h"

using namespace System;
using namespace System::Drawing;

namespace NS_services
{
	CLserviceImage::CLserviceImage(void)
	{
		this->image = gcnew NS_composants::CLimages();
	}
	Bitmap^ CLserviceImage::lireImage(String^ image)
	{
		return this->image->acquisitionImage(image);
	}
}
