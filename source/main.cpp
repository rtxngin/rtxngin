#include <iostream>
#include <fstream>

int main()
{
	int image_width = 256;
	int image_height = 256;

	std::ofstream image("image.ppm");

	image << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for(int j = 0; j < image_height; ++j)
	{
		for(int i = 0; i < image_width; ++i)
		{
			auto r = double(i) / (image_width-1);
			auto g = double(j) / (image_height-1);
			auto b = 0;

			int ir = static_cast<int>(255.999 * r);
			int ig = static_cast<int>(255.999 * g);
			int ib = static_cast<int>(255.999 * b);

			image << ir << ' ' << ig << ' ' << ib << '\n';
		}
	}
}