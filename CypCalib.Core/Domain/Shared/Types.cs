using absLib.Types;

namespace CypCalib.Core.Domain.Shared
{
    public class Types
    {
        /**
         * @brief 对基本类型的封装，虽然现有的跟踪仪数据是 3 自由度，但是存在有 6 自由度测量的场景
         */
        public class Laser3Dof
        {
            private Point3D Data { get; set; }

            public double X => Data.X;
            public double Y => Data.Y;
            public double Z => Data.Z;

            public Laser3Dof()
            {
                Data = new Point3D();
            }
            
            public Laser3Dof(double x, double y, double z)
            {
                Data = new Point3D(x, y, z);
            }
        }
        
        /**
         * @brief 6 自由度机械臂 Mcs 坐标与激光跟踪仪数据的配对
         */
        public class Robot6DLaserData
        {
            public Point6D Mcs { get; set; }
            public Laser3Dof Laser { get; set; }

            public Robot6DLaserData()
            {
                Mcs = new Point6D();
                Laser = new Laser3Dof();
            }

            public Robot6DLaserData(Point6D mcs, Laser3Dof laser)
            {
                Mcs = mcs;
                Laser = laser;
            }
        }
        
        /**
         * @brief 机械臂描述模型，包括 DH 模型、减速比、耦合比等
         */
        public struct Robot6DInfo
        {
            public double[] A { get; set; }
            public double[] D { get; set; }
            public double[] Origin { get; set; }
            public double[] Alpha { get; set; }
            public double[] Reduction { get; set; }
            public double J4J5Ratio { get; set; }
            public double J4J6Ratio { get; set; }
            public double J5J6Ratio { get; set; }

            public Robot6DInfo(double[] a, double[] d, double[] origin, double[] alpha, double[] reduction,
                double j4J5Ratio, double j4J6Ratio, double j5J6Ratio)
            {
                A = a;
                D = d;
                Origin = origin;
                Alpha = alpha;
                Reduction = reduction;
                J4J5Ratio = j4J5Ratio;
                J4J6Ratio = j4J6Ratio;
                J5J6Ratio = j5J6Ratio;
            }
        }
    }
}