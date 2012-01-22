require 'spec_helper'

describe HashSample do
  context "new key" do
    subject { HashSample.new }
    it { subject.make_hash.class.should == Hash }
  end

  context "hash_val_nil" do
    it {
      hs = HashSample.new
      lambda {
        hs.hash_val_nil?("test", nil)
      }.should raise_error(TypeError)
    }

    it {
      h = {
        "test" => "value",
        :sym_key => "sym_val",
      }

      hs = HashSample.new
      hs.hash_val_nil?(h, "test").should be_true
      hs.hash_val_nil?(h, :sym_key).should be_true

      hs.hash_val_nil?(h, "test2").should be_false

      hs.has_test_sym?(h).should be_false
    }

    it {
      h = {
        "test" => "value",
        :sym_key => "sym_val",
      }
      hs = HashSample.new
      hs.has_test_sym?(h).should be_false
    }

    it {
      h = {
        :test => "value",
        :sym_key => "sym_val",
      }
      hs = HashSample.new
      hs.has_test_sym?(h).should be_true
    }
  end
end
