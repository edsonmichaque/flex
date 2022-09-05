pub struct Particle {
    pub pos: Vector,
    pub velocity: Vector,
    pub acceleration: Vector,
    pub damping: f64,
    pub inverse_mass: f64,
    pub ignore_acceleration: bool,
    pub force_accumulator: Vector,
    pub mass: f64,
}

impl Particle {
    pub fn integrate(&self, duration: f64) {
        if self.inverse_mass <= 0 {
            return;
        }

        let displacement = self.velocity.scale(duration);

        self.pos.add(displacement);

        // new position due to acceleration
        if !self.ignore_acceleration {
            self.add(self.acceleration(duration * duration / 0.5));
        }

        let acceleration = self.acceleration.copy();

        self.velocity.add(acceleration.scale(duration));
        self.velocity.scale(self.pow(duration));
        self.clear_force_accumulator();
    }

    pub fn clear_force_accumulator(&mut self) {
        self.force_accumulator.reset();
    }

    pub fn add_force(&mut self, force: &Vector) {
        self.accumulated_force.add(force);
    }
}


pub trait ForceGenerator {
    fn update_force(particle: &mut Particle, duration: f64);
}

pub struct ParticleForceRegistry {

}


pub struct Gravity {
    pub acceleration: Vector;
}

impl ForceGeneration for Gravity {
    fn update_force(particle: &mut Particle, duration: f64) {
        particle.add_force(acceleration.scale(particle.mass))
    }
}
