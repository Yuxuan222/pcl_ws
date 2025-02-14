#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>

typedef pcl::PointXYZ Point;
typedef pcl::PointCloud<Point> PointCloud;
typedef pcl::PCLPointCloud2 PointCloud2;
typedef PCLPointCloud2::Ptr PointCloud2Ptr;
typedef pcl::VoxelGrid<PointCloud2> VoxelGrid;

int main (int argc, char** argv){

    PointCloud2Ptr cloud (new PointCloud2 ());
    PointCloud2Ptr cloud_filtered (new PointCloud2 ());

    // Fill in the cloud data
    pcl::PCDReader reader;
    // Replace the path below with the path where you saved your file
    reader.read ("../data/table_scene_lms400.pcd", *cloud); // Remember to change the path to your file!!!

    std::cerr << "PointCloud before filtering: " << cloud->width * cloud->height << " data points." << std::endl;

    // Create the filtering object
    VoxelGrid sor;
    sor.setInputCloud (cloud);
    sor.setLeafSize (0.01f, 0.01f, 0.01f);
    sor.filter (*cloud_filtered);

    std::cerr << "PointCloud after filtering: " << cloud_filtered->width * cloud_filtered->height << " data points." << std::endl;

    pcl::PCDWriter writer;
    writer.write ("../data/table_scene_lms400_downsampled.pcd", *cloud_filtered, Eigen::Vector4f::Zero (), Eigen::Quaternionf::Identity (), false);

    return (0);
}