#ifndef COMMON_HPP
#define COMMON_HPP

#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/registration/icp.h>

typedef pcl::PointXYZ Point;
typedef pcl::PointCloud<Point> PointCloud;
typedef PointCloud::Ptr PointCloudPtr;
typedef pcl::IterativeClosestPoint<Point, Point> ICP;

typedef pcl::ApproximateVoxelGrid<Point> ApproximateVoxelGrid;

typedef pcl::NormalDistributionsTransform<Point, Point> NDT;

typedef Eigen::Matrix4f Matrix4f;
typedef Eigen::Affine3f Affine3f;
typedef Eigen::Vector3f Vector3f;
typedef Eigen::AngleAxisf AngleAxisf;


#endif // COMMON_HPP