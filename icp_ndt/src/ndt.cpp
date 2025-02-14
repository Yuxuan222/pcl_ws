#include "common.hpp"

int main (int argc, char** argv){
    //init
    PointCloudPtr cloud_1 (new PointCloud());
    PointCloudPtr cloud_2 (new PointCloud());
    PointCloudPtr cloud_filtered (new PointCloud());
    
    // Load point cloud1 and point cloud2
    if (pcl::io::loadPCDFile<Point> ("../pcd/room_scan1.pcd", *cloud_1) == -1){
        PCL_ERROR ("Couldn't read file room_scan1.pcd \n");
        return (-1);
    }
    std::cout << "Loaded " << cloud_in->size() << " data points from room_scan1.pcd" << std::endl;

    if (pcl::io::loadPCDFile<Point> ("../pcd/room_scan2.pcd", *cloud_2) == -1){
        PCL_ERROR ("Couldn't read file room_scan2.pcd \n");
        return (-1);
    }
    std::cout << "Loaded " << cloud_in->size() << " data points from room_scan2.pcd" << std::endl;

    // Filtering
    ApproximateVoxelGrid approximate_voxel_filter;
    approximate_voxel_filter.setLeafSize (0.2, 0.2, 0.2);
    approximate_voxel_filter.setInputCloud (cloud_2);
    approximate_voxel_filter.filter (*cloud_filtered);
    std::cout << "Filtered cloud contains " << cloud_filtered->size() << " data points from room_scan2.pcd" << std::endl;

    // NTD
    NDT ndt;
    ntd.setTransformationEpsilon (0.01);
    ntd.setStepSize (0.1);
    ntd.setResolution (1.0);
    ntd.setMaximumIterations (35);
    ntd.setInputSource (cloud_filtered);
    ntd.setInputTarget (cloud_1);

    
    


}