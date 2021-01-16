use crate::SbpString;

pub trait SbpSerialize {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>);
    fn sbp_size(&self) -> usize;
}

impl SbpSerialize for u8 {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        buf.extend(&self.to_le_bytes())
    }

    fn sbp_size(&self) -> usize {
        1
    }
}

impl SbpSerialize for u16 {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        buf.extend(&self.to_le_bytes())
    }

    fn sbp_size(&self) -> usize {
        2
    }
}

impl SbpSerialize for u32 {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        buf.extend(&self.to_le_bytes())
    }

    fn sbp_size(&self) -> usize {
        4
    }
}

impl SbpSerialize for u64 {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        buf.extend(&self.to_le_bytes())
    }

    fn sbp_size(&self) -> usize {
        8
    }
}

impl SbpSerialize for i8 {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        buf.extend(&self.to_le_bytes())
    }

    fn sbp_size(&self) -> usize {
        1
    }
}

impl SbpSerialize for i16 {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        buf.extend(&self.to_le_bytes())
    }

    fn sbp_size(&self) -> usize {
        2
    }
}

impl SbpSerialize for i32 {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        buf.extend(&self.to_le_bytes())
    }

    fn sbp_size(&self) -> usize {
        4
    }
}

impl SbpSerialize for i64 {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        buf.extend(&self.to_le_bytes());
    }

    fn sbp_size(&self) -> usize {
        8
    }
}

impl SbpSerialize for f32 {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        // This really should be self.to_le_bytes().to_vec() once it's a stable feature
        buf.extend(&self.to_bits().to_le_bytes());
    }

    fn sbp_size(&self) -> usize {
        4
    }
}

impl SbpSerialize for f64 {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        // This really should be self.to_le_bytes().to_vec() once it's a stable feature
        buf.extend(&self.to_bits().to_le_bytes());
    }

    fn sbp_size(&self) -> usize {
        8
    }
}

impl SbpSerialize for SbpString {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        buf.extend(self.as_bytes());
    }

    fn sbp_size(&self) -> usize {
        self.0.len()
    }
}

impl<T: SbpSerialize> SbpSerialize for &'_ [T] {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.iter().for_each(|item| item.append_to_sbp_buffer(buf));
    }

    fn sbp_size(&self) -> usize {
        self.iter().map(|item| item.sbp_size()).sum()
    }
}

impl<T: SbpSerialize> SbpSerialize for Vec<T> {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.as_slice().append_to_sbp_buffer(buf)
    }

    fn sbp_size(&self) -> usize {
        self.as_slice().sbp_size()
    }
}

impl<T: SbpSerialize, const SIZE: usize> SbpSerialize for [T; SIZE] {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.as_ref().append_to_sbp_buffer(buf)
    }

    fn sbp_size(&self) -> usize {
        self.as_ref().sbp_size()
    }
}
