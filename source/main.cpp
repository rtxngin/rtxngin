#include <iostream>
#include <fstream>

#include <minifb.h>

#include "color.hpp"
#include "vector3.hpp"
#include "ray.hpp"
#include "hittable.hpp"
#include "hittable_list.hpp"
#include "sphere.hpp"
#include "rtweekend.hpp"
#include "camera.hpp"

uint32_t* buffer = nullptr;
struct mfb_window* window = nullptr;

int main()
{
	hittable_list world;

	auto material_ground = std::make_shared<lambertian>(color(0.8, 0.8, 0.0));
	auto material_center = std::make_shared<lambertian>(color(0.1, 0.2, 0.5));
	auto material_left = std::make_shared<dielectric>(1.5);
	auto material_right = std::make_shared<metal>(color(0.8, 0.6, 0.2), 0.0);
	auto material_top = std::make_shared<metal>(color(0.2, 0.8, 0.2), 0.1);
	auto material_bottom = std::make_shared<lambertian>(color(0.5, 0.2, 0.8));
	auto material_back = std::make_shared<dielectric>(1.5);

	world.add(std::make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, material_ground));
	world.add(std::make_shared<sphere>(point3( 0.0, 0.0, -1.0), 0.5, material_center));
	world.add(std::make_shared<sphere>(point3(-1.0, 0.0, -1.0), 0.5, material_left));
	world.add(std::make_shared<sphere>(point3(-1.0, 0.0, -1.0), -0.4, material_left));
	world.add(std::make_shared<sphere>(point3( 1.0, 0.0, -1.0), 0.5, material_right));
	world.add(std::make_shared<sphere>(point3(0.0, 1.0, -5.0), 1.0, material_top));
	world.add(std::make_shared<sphere>(point3(0.0, -1.0, -5.0), 1.0, material_bottom));
	world.add(std::make_shared<sphere>(point3(4.0, 0.0, -4.0), 2.0, material_back));

	camera cam;

	cam.aspect_ratio = 16.0 / 9.0;
	cam.image_width = 800;
	cam.samples_per_pixel = 100;
	cam.max_depth = 50;

	cam.vfov = 60;
	cam.lookfrom = point3(-2, 2, 1);
	cam.lookat = point3(0, 0, -1);
	cam.vup = vec3(0, 1, 0);

	cam.defocus_angle = 0.0;
	cam.focus_dist = 10.0;

	cam.initialize();

	window = mfb_open_ex("RTXNGIN", cam.image_width, cam.image_height, WF_RESIZABLE);
	if (!window)
	{
		throw std::runtime_error("Failed to create a window!");
	}

	buffer = (uint32_t*)malloc(cam.image_width * cam.image_height * 4);

	do
	{
		int state = mfb_update_ex(window, buffer, cam.image_width, cam.image_height);

		cam.render(world);

		if(state < 0)
		{
			window = nullptr;
			break;
		}
	} while (mfb_wait_sync(window));

	free(buffer);
	mfb_close(window);
}