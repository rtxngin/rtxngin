#include <iostream>
#include <fstream>

#include "color.hpp"
#include "vector3.hpp"
#include "ray.hpp"
#include "hittable.hpp"
#include "hittable_list.hpp"
#include "sphere.hpp"
#include "rtweekend.hpp"
#include "camera.hpp"

int main()
{
	hittable_list world;

	auto material_ground = std::make_shared<lambertian>(color(0.0, 0.0, 0.0));
	auto material_center = std::make_shared<lambertian>(color(0.7, 0.3, 0.3));
	auto material_left   = std::make_shared<metal>(color(0.8, 0.8, 0.8));
	auto material_right  = std::make_shared<metal>(color(0.8, 0.6, 0.2));

	world.add(std::make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, std::make_shared<lambertian>(color(0.2, 0.2, 0.2))));
	world.add(std::make_shared<sphere>(point3( 0.0, 0.0, -1.0), 0.5, std::make_shared<lambertian>(color(0.7, 0.3, 0.3))));
	world.add(std::make_shared<sphere>(point3( 1.0, 1.0, -1.0), 0.5, std::make_shared<metal>(color(0.1, 0.1, 0.1))));

	camera cam;

	cam.aspect_ratio = 16.0 / 9.0;
	cam.image_width = 400;
	cam.samples_per_pixel = 100;
	cam.max_depth = 50;

	cam.render(world);
}