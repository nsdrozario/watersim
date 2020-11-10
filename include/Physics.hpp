#ifndef WATERSIM_PHYSICS_HPP
#define WATERSIM_PHYSICS_HPP

namespace watersim {
    struct Physics {
        static int g;
        static int spreadVelocity;
        static void simulateFrame();
    };
}


#endif